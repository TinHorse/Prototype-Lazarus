// Fill out your copyright notice in the Description page of Project Settings.

#include "TownControl.h"
#include "House.h"
#include "Town.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "Market.h"
#include "Manufacture.h"
#include "LightMill.h"
#include "MiningVessel.h"
#include "Diplomacy.h"
#include "CommandUnitControl.h"
#include "AnchorPoint.h"
#include "Contract.h"


ATownControl::ATownControl()
{
	// initialize subcomponents
	market = CreateDefaultSubobject<UMarket>("Market");
	diplomacy = CreateDefaultSubobject<UDiplomacy>("Diplomacy");

	// set spawn parameters for buildings
	buildingSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	buildingSpawnParameters.bNoFail = true;
	buildingSpawnParameters.Owner = this;
	buildingSpawnParameters.Instigator = AController::GetPawn();

	// set array of spawnTransforms (positions and rotations of buildings)
	int num_transforms = 9;
	int num_layers = 4;


	for (int i = 1; i < num_layers + 1; i++) {
		FTransform transform;

		for (int j = 0; j < num_transforms; j++) {
			if ((j%(num_transforms/3)) != 0) {
				float value = (((2 * PI) / (num_transforms))*j);

				float distance = 80;
				FVector location{ float(i) * distance * FMath::Sin(value) + (distance/2) * FMath::Sin(value), float(i) * (distance / 2) * FMath::Cos(value) + distance * FMath::Cos(value),0 };
				transform.SetLocation(location);

				FVector rot = { FMath::Sin(value),FMath::Cos(value),0 };
				FVector rotation{ rot.X,rot.Y,0 };
				transform.SetRotation(rotation.ToOrientationQuat());

				FVector Scalar{ float(i * 2) / num_layers + 1,float(i * 3) / num_layers + 1,1 };
				transform.SetScale3D(Scalar);
				spawnTransform.Add(transform);
			}
		}
		num_transforms+=i;
	}
	spawnIndex = 0;

	market->addLabour(10);
	market->addLight(2);
	market->addEquipment(10);
	market->addLabourDemand(10);

}


void ATownControl::setAnchorPoints()
{
	// Anchor Points

	for (int j = 1; j <= 3; j++) {
		float value = (((2 * PI) / 3) * j);
		FTransform anchor_transform;
		float distance = 80;
		FVector location{ 5.5f * distance * FMath::Sin(value), 5.5f * distance * FMath::Cos(value),0 };
		anchor_transform.SetLocation(location + AController::GetPawn()->GetActorLocation());

		FVector rot = { FMath::Sin(value),FMath::Cos(value),0 };
		FVector rotation{ rot.X,rot.Y,0 };
		anchor_transform.SetRotation(rotation.ToOrientationQuat());

		AAnchorPoint* anchor = GetWorld()->SpawnActor<AAnchorPoint>(anchorpointClass, anchor_transform, buildingSpawnParameters);
		anchorPoints.Add(anchor);
	}
}

void ATownControl::addHouse()
{

	if (spawnIndex < spawnTransform.Num()) {
		spawnTransform[spawnIndex].SetLocation(spawnTransform[spawnIndex].GetLocation() + AController::GetPawn()->GetActorLocation());
		spawnTransform[spawnIndex].SetRotation(spawnTransform[spawnIndex].GetRotation());


		ABuilding* building = GetWorld()->SpawnActor<ABuilding>(houseClass, spawnTransform[spawnIndex], buildingSpawnParameters);
		buildings.Add(building);

		spawnIndex++;
	}
}

void ATownControl::addManufacture()
{

	if (spawnIndex < spawnTransform.Num()) {
		spawnTransform[spawnIndex].SetLocation(spawnTransform[spawnIndex].GetLocation() + AController::GetPawn()->GetActorLocation());
		spawnTransform[spawnIndex].SetRotation(spawnTransform[spawnIndex].GetRotation());


		ABuilding* building = GetWorld()->SpawnActor<ABuilding>(manufactureClass, spawnTransform[spawnIndex], buildingSpawnParameters);
		buildings.Add(building);

		spawnIndex++;
	}
}

void ATownControl::addLightMill()
{
	if (spawnIndex < spawnTransform.Num()) {
		spawnTransform[spawnIndex].SetLocation(spawnTransform[spawnIndex].GetLocation() + AController::GetPawn()->GetActorLocation());
		spawnTransform[spawnIndex].SetRotation(spawnTransform[spawnIndex].GetRotation());


		ABuilding* building = GetWorld()->SpawnActor<ABuilding>(lightmillClass, spawnTransform[spawnIndex], buildingSpawnParameters);
		buildings.Add(building);

		spawnIndex++;
	}
}


void ATownControl::deleteBuilding(int index)
{
	buildings[index]->Destroy();
}

void ATownControl::addMiner()
{
	int anchor_index = FMath::RandRange(0, 2);
	if (AAnchorPoint* Anchor = Cast<AAnchorPoint>(anchorPoints[anchor_index])) {

		FTransform transform = Anchor->GetRootComponent()->GetRelativeTransform();
		FActorSpawnParameters spawn_params;

		spawn_params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		spawn_params.bNoFail = true;
		spawn_params.Owner = this;
		spawn_params.Instigator = AController::GetPawn();


		AMiningVessel* vessel = GetWorld()->SpawnActor<AMiningVessel>(contractorClass, transform, buildingSpawnParameters);
		// add to market or diplomacy, scan function to check for vessels in the area
		vessel->SpawnDefaultController();
		vessel->GetController()->SetInitialLocationAndRotation(vessel->GetActorLocation(), vessel->GetActorRotation());
	}
}

TArray<ABuilding*>& ATownControl::getBuildings()
{
	return buildings;
}
UDiplomacy* ATownControl::getDiplomacy()
{
	return diplomacy;
}


void ATownControl::executeMarketInteractions()
{
	//market->addTitanium(2000);

	market->addLightDemand(market->getLabour() * 0.1);
	market->addLight(-market->getLabour() * 0.1);

	market->normalizeDemands();
	market->setThresholds();


	for (auto b : buildings) {
		if (ABuilding* building = Cast<ABuilding>(b)) {
			building->interactWithMarket(market);
		}
	}	
	
	if (market->getEquipmentDemand() > total_equipment_production) {
		addManufacture();
	}
	if (market->getLabourDemand() > (total_worker_production * 10)) {
		addHouse();
	}
	if (market->getLightDemand() > (total_light_production)) {
		addLightMill();
	}
	if (market->getTitaniumDemand() > (total_titanium_production)) {
		//addMiner();
	}

	/*
	UE_LOG(LogTemp, Warning, TEXT("market titanium demand %f"), market->getTitaniumDemand());
	UE_LOG(LogTemp, Warning, TEXT("market labour demand %f"), market->getLabourDemand());
	UE_LOG(LogTemp, Warning, TEXT("market equipment demand %f"), market->getEquipmentDemand());
	UE_LOG(LogTemp, Warning, TEXT("market light demand %f"), market->getLightDemand());
	UE_LOG(LogTemp, Warning, TEXT(" "));
	*/

}

void ATownControl::executeBuildingProduction()
{
	for (auto b : buildings) {
		if (ABuilding* building = Cast<ABuilding>(b)) {
			building->produce(market, 5.f);
		}
	}
	
	/*
	UE_LOG(LogTemp, Warning, TEXT("1 market titanium %f"), market->getTitanium());
	UE_LOG(LogTemp, Warning, TEXT("1 market labour %f"), market->getLabour());
	UE_LOG(LogTemp, Warning, TEXT("1 market equipment %f"), market->getEquipment());
	UE_LOG(LogTemp, Warning, TEXT("1 market light %f"), market->getLight());
	UE_LOG(LogTemp, Warning, TEXT(" "));
	*/
	
}



void ATownControl::calculateStatus(TArray<class AActor*> CommandControllers, TArray<class AActor*> TownControllers)
{
	UE_LOG(LogTemp, Warning, TEXT("name %s"), *GetPawn()->GetName());


	// amount of buildings and total production calculations, accumulate firepower
	num_houses = 0;
	num_manufactures = 0;
	num_lightmills = 0;
	num_towers = 0;

	total_titanium_production = 0;
	total_light_production = 0;
	total_worker_production = 0;
	total_equipment_production = 0;

	firepower = 1;
	for (auto b : buildings) {
		if (AHouse* h = Cast<AHouse>(b)) {
			num_houses++;
			total_worker_production += h->getMaxOutput();
			firepower += b->getFirepower();
		}
		else if (AManufacture* m = Cast<AManufacture>(b)) {
			num_manufactures++;
			total_equipment_production += m->getMaxOutput();
			firepower += b->getFirepower();
		}
		else if (ALightMill* m = Cast<ALightMill>(b)) {
			num_lightmills++;
			total_light_production += m->getMaxOutput();
			firepower += b->getFirepower();
		}
		// ADD TOWERS
	}

	total_equipment_production += market->total_equipment_production;
	total_light_production += market->total_light_production;
	total_titanium_production += market->total_titanium_production;
	total_worker_production += market->total_worker_production;
	market->total_equipment_production = 0;
	market->total_light_production = 0;
	market->total_titanium_production = 0;
	market->total_worker_production = 0;


	// accumulate wealth
	wealth = 1;
	wealth += market->getTitanium();
	wealth += market->getEquipment();
	wealth += market->getLabour();
	wealth += market->getLight();
	wealth += market->getLightPowder();
	wealth += market->getBooks();
	if (wealth <= 0) {
		wealth = 1;
	}

	TArray<ACommandUnitControl*> commands;
	// get firepower of strongest hostile command
	float strongest_other_firepower = 0;
	for (auto command : CommandControllers) {
		if (ACommandUnitControl* com = Cast<ACommandUnitControl>(command)) {
			commands.Add(com);
			float f = com->getFirepower();
			if (f > strongest_other_firepower) {
				strongest_other_firepower = f;
			}
		}
	}
	
	// calculate fear
	if (strongest_other_firepower > firepower) {
		///UE_LOG(LogTemp, Warning, TEXT("%f firepower"), firepower);
		///UE_LOG(LogTemp, Warning, TEXT("%f other firepower total"), strongest_other_firepower);
		fear += ((strongest_other_firepower / firepower) - 1) * 10;
		///UE_LOG(LogTemp, Warning, TEXT("%f fear delta"), ((strongest_other_firepower / firepower) - 1) * 10);
		///UE_LOG(LogTemp, Warning, TEXT("%f fear"), fear);
	}
	fear -= (disciples + seperatists) / 10;
	if (fear < 0) {
		fear = 0;
	}

	// accumulate wealth of other towns
	float other_wealth = 0;
	float num = 0;
	TArray<ATownControl*> towns;
	for (auto t : TownControllers) {
		if (ATownControl* townController = Cast<ATownControl>(t)) {
			towns.Add(townController);
			other_wealth += townController->getWealth();
			num++;
		}
	}
	if (num > 0) {
		other_wealth /= num;
		///UE_LOG(LogTemp, Warning, TEXT("%f other_wealth"), other_wealth);
		///UE_LOG(LogTemp, Warning, TEXT("%f wealth"), wealth);
	}

	// calculate supremacy
	supremacy += ((wealth / other_wealth) - 1) * 10;
	supremacy += blackcoats / 10;
	if (supremacy < 0) {
		supremacy = 0;
	}

	
	// add light powder demand
	market->addLightPowderDemand(magnates);

	if (supremacy > 10) {
		generateEliminationContract(commands, towns);
	}
}

void ATownControl::generateEliminationContract(TArray<class ACommandUnitControl*>& CommandControllers, TArray<class ATownControl*>& TownControllers)
{
	UE_LOG(LogTemp, Warning, TEXT("generating elmination contract"));

}

float ATownControl::getFirepower()
{
	return firepower;
}

float ATownControl::getWealth()
{
	return wealth;
}

float ATownControl::getSupremacy()
{
	return supremacy;
}

float ATownControl::getStability()
{
	return stability;
}

