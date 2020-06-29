// Fill out your copyright notice in the Description page of Project Settings.

#include "CommandUnitControl.h"
#include "Inventory.h"
#include "Market.h"
#include "Diplomacy.h"
#include "Engine/World.h"
#include "Miner.h"
#include "Unit.h"
#include "MiningVessel.h"
#include "MinerControl.h"


ACommandUnitControl::ACommandUnitControl() {
	inventory = CreateDefaultSubobject<UInventory>("Inventory");
	diplomacy = CreateDefaultSubobject<UDiplomacy>("Diplomacy");
}

void ACommandUnitControl::interactWithMarket(UMarket* market) {
	market->addTitanium(inventory->getTitanium());
	market->total_titanium_production += inventory->getTitanium();
	//UE_LOG(LogTemp, Warning, TEXT("%f market->total_titanium_production"), market->total_titanium_production);
	//UE_LOG(LogTemp, Warning, TEXT("%f inventory->getTitanium()"), inventory->getTitanium());
	inventory->setTitanium(0);
}

UDiplomacy * ACommandUnitControl::getDiplomacy()
{
	return diplomacy;
}

UInventory * ACommandUnitControl::getInventory()
{
	//UE_LOG(LogTemp, Warning, TEXT("%f titanium"), inventory->getTitanium());
	return inventory;
}

void ACommandUnitControl::spawnMiner(FVector location)
{
	FTransform transform = GetRootComponent()->GetRelativeTransform();
	transform.SetLocation(location);
	FActorSpawnParameters spawn_params;
	

	spawn_params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	spawn_params.bNoFail = true;
	spawn_params.Owner = this;
	spawn_params.Instigator = AController::GetPawn();
	

	AMiner* miner = GetWorld()->SpawnActor<AMiner>(minerClass, transform, spawn_params);
	// add to market or diplomacy, scan function to check for vessels in the area
	miner->SpawnDefaultController();
	miner->GetController()->SetInitialLocationAndRotation(miner->GetActorLocation(), miner->GetActorRotation());
	if (AMinerControl* control = Cast<AMinerControl>(miner->GetController())) {
		control->setCommandingUnit(this);
		unit_controllers.Add(control);
	}
	if (AMiningVessel* commandingUnit = Cast<AMiningVessel>(AController::GetPawn())) {
		miner->setFaction(commandingUnit->getFaction());
	}
	
}

void ACommandUnitControl::calculateStatus(TArray<class AActor*> CommandControllers, TArray<class AActor*> TownControllers)
{
	// accumulate firepower
	firepower = 0;
	for (auto unit : unit_controllers) {
		if (ABaseUnitController* u = Cast<ABaseUnitController>(unit)) {
			firepower += u->getFirepower();
			///UE_LOG(LogTemp, Warning, TEXT("%f firepower ++"), firepower);
		}
	}

	// accumulate wealth
	wealth = 0;
	wealth += inventory->getTitanium();
	wealth += inventory->getEquipment();
	wealth += inventory->getLabour();
	wealth += inventory->getLight();
	wealth += inventory->getLightPowder();
	wealth += inventory->getBooks();
	if (wealth <= 0) {
		wealth = 1;
	}

	// other firepower
	float other_firepower = 0;
	int amount = 0;
	for (auto command : CommandControllers) {
		if (ACommandUnitControl* com = Cast<ACommandUnitControl>(command)) {
			other_firepower += com->getFirepower();
			amount++;
		}
	}
	if (amount > 0) {
		///UE_LOG(LogTemp, Warning, TEXT("%f firepower"), firepower);
		///UE_LOG(LogTemp, Warning, TEXT("%f other firepower total"), other_firepower);
		other_firepower /= amount;
		///UE_LOG(LogTemp, Warning, TEXT("%f other firepower average"), other_firepower);
		fear += ((other_firepower / firepower) - 1) * 2;
		///UE_LOG(LogTemp, Warning, TEXT("%f fear delta"), ((other_firepower / firepower) - 1) * 2);
		///UE_LOG(LogTemp, Warning, TEXT("%f fear"), fear);
	}
	
	desperation -= ((wealth / 1000) - 1) * 2;
}

float ACommandUnitControl::getFirepower()
{
	return firepower;
}

float ACommandUnitControl::getWealth()
{
	return wealth;
}

TArray<class ABaseUnitController*>& ACommandUnitControl::getUnitControllers()
{
	return unit_controllers;
}

