// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"
#include "Components/StaticMeshComponent.h"
#include "Market.h"

// Sets default values
ABuilding::ABuilding()
{
	PrimaryActorTick.bCanEverTick = false;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(mesh);
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


float ABuilding::calculateLabourDemand(float target_output)
{
	if (target_output > max_output) {
		target_output = max_output;
	}
	target_labour = target_output / output_per_labour;
	//UE_LOG(LogTemp, Warning, TEXT("target_output %f"), target_output);
	labour_demand = (efficiency * target_labour) - getLabour();
	return labour_demand;
}

void ABuilding::addLabour(UMarket * market, float threshold)
{
	if (labour_demand > threshold) {
		labour_demand = threshold;
	}
	labour += labour_demand;
	market->addLabour(-labour_demand);
	//UE_LOG(LogTemp, Warning, TEXT("threshold labour %f"), labour_threshold);
	//UE_LOG(LogTemp, Warning, TEXT("labour %f"), labour);
}

float ABuilding::calculateInputDemand()
{
	//UE_LOG(LogTemp, Warning, TEXT("input_demand %f"), input_demand);
	return input_demand = target_labour * input_per_labour;
}

void ABuilding::produce(UMarket * market, float num_cycles)
{
	
}

void ABuilding::interactWithMarket(UMarket* market)
{

}

float ABuilding::getLabour()
{
	return labour;
}

void ABuilding::setLabour(float lab)
{
	labour = lab;
}

float ABuilding::getMaxOutput()
{
	return max_output;
}

float ABuilding::getFirepower()
{
	return firepower;
}

