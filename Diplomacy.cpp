// Fill out your copyright notice in the Description page of Project Settings.

#include "Diplomacy.h"
#include "MiningVessel.h"
#include "Town.h"
#include "AIController.h"

// Sets default values for this component's properties
UDiplomacy::UDiplomacy()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}

/*
TArray<AMiningVessel*>& UDiplomacy::getMiners()
{
	return contractors_in_area;
}

TArray<class ATown*>& UDiplomacy::getTowns()
{
	return towns_in_area;
}
*/


float UDiplomacy::getScanRadius()
{
	return scanRadius;
}

void UDiplomacy::setScanRadius(float rad)
{
	scanRadius = rad;
}


// Called when the game starts
void UDiplomacy::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDiplomacy::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}