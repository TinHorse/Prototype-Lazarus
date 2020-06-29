// Fill out your copyright notice in the Description page of Project Settings.

#include "DebrisComp.h"

// Sets default values for this component's properties
UDebrisComp::UDebrisComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	health = 0;
	// ...
}


// Called when the game starts
void UDebrisComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

int UDebrisComp::getHealth()
{
	return health;
}

void UDebrisComp::decrementHealthBy(int h)
{
	health -= h;
}

int UDebrisComp::getTitaniumDensity()
{
	return titanium_density;
}

void UDebrisComp::setTitaniumDensity(int density)
{
	titanium_density = density;
}
