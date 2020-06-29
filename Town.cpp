// Fill out your copyright notice in the Description page of Project Settings.

#include "Town.h"
#include "Building.h"
#include "House.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATown::ATown()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(mesh);
	faction = EFactionEnum::Blackcoats;
}


// Called when the game starts or when spawned
void ATown::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATown::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATown::message()
{
	UE_LOG(LogTemp, Warning, TEXT("cast successful"));
}

void ATown::setFaction(TEnumAsByte<EFactionEnum> value)
{
	faction = value;
}

TEnumAsByte<EFactionEnum> ATown::getFaction()
{
	return faction;
}