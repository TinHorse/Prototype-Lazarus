// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STRUCTS.h"
#include "Unit.generated.h"

UCLASS()
class TOWNSIMULATOR_API AUnit : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Factions")
		TEnumAsByte<EFactionEnum> faction;
public:
	// Sets default values for this pawn's properties
	AUnit();
	UFUNCTION(BlueprintCallable, Category = "Factions")
		void setFaction(TEnumAsByte<EFactionEnum> value);
	UFUNCTION(BlueprintCallable, Category = "Factions")
		TEnumAsByte<EFactionEnum> getFaction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
