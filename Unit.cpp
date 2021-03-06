// Fill out your copyright notice in the Description page of Project Settings.

#include "Unit.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AUnit::AUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AUnit::setFaction(TEnumAsByte<EFactionEnum> value)
{
	faction = value;
}

TEnumAsByte<EFactionEnum> AUnit::getFaction()
{
	return faction;
}

