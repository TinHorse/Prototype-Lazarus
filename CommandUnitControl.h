// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CommandUnitControl.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API ACommandUnitControl : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "Inventory")
		class UInventory* inventory;
	UPROPERTY(EditAnywhere, Category = "Diplomacy")
		class UDiplomacy* diplomacy;

	UPROPERTY(EditAnywhere, Category = "Units")
		TArray<class ABaseUnitController*> unit_controllers;
	UPROPERTY(EditAnywhere, Category = "Miners")
		TSubclassOf<class AMiner> minerClass;

	UPROPERTY(EditAnywhere, Category = "Status")
		float firepower{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float wealth{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float fear{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float desperation{ 0 };

public:
	ACommandUnitControl();
	UFUNCTION(BlueprintCallable, Category = "Town Interaction")
		void interactWithMarket(UMarket * market);

	UFUNCTION(BlueprintCallable, Category = "Diplomacy")
		class UDiplomacy* getDiplomacy();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		class UInventory* getInventory();
	UFUNCTION(BlueprintCallable, Category = "Units")
		void spawnMiner(FVector location);

	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		void calculateStatus(TArray<class AActor*> CommandControllers, TArray<class AActor*> TownControllers);
	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		float getFirepower();
	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		float getWealth();

	UFUNCTION(BlueprintCallable, Category = "Units")
		TArray<class ABaseUnitController*>& getUnitControllers();
};
