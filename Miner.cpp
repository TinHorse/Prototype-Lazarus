// Fill out your copyright notice in the Description page of Project Settings.

#include "Miner.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMiner::AMiner()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
}

// Called when the game starts or when spawned
void AMiner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMiner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMiner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

