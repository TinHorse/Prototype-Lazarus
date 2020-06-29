// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TownControl.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API ATownControl : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class ABuilding*> buildings;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TArray<class AAnchorPoint*> anchorPoints;
	UPROPERTY(EditAnywhere, Category = "Contracts")
		TArray<class UContract*> contracts;

	UPROPERTY(EditAnywhere, Category = "Market")
		class UMarket* market;
	UPROPERTY(EditAnywhere, Category = "Diplomacy")
		class UDiplomacy* diplomacy;

	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AHouse> houseClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AManufacture> manufactureClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class ALightMill> lightmillClass;
	UPROPERTY(EditAnywhere, Category = "Buildings")
		TSubclassOf<class AAnchorPoint> anchorpointClass;
	UPROPERTY(EditAnywhere, Category = "Contractors")
		TSubclassOf<class AMiningVessel> contractorClass;

	UPROPERTY(EditAnywhere, Category = "Status")
		float firepower{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float wealth{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float fear{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float supremacy{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float stability{ 0 };

	UPROPERTY(EditAnywhere, Category = "Status")
		float blackcoats{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float seperatists{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float disciples{ 0 };
	UPROPERTY(EditAnywhere, Category = "Status")
		float magnates{ 0 };


	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void setAnchorPoints();

public:
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void addHouse();
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void addManufacture();
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void addLightMill();
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void deleteBuilding(int index);

	UFUNCTION(BlueprintCallable, Category = "Contractors")
		void addMiner();

	UFUNCTION(BlueprintCallable, Category = "Buildings")
		TArray<class ABuilding*>& getBuildings();
	UFUNCTION(BlueprintCallable, Category = "Diplomacy")
		class UDiplomacy* getDiplomacy();



	UFUNCTION(BlueprintCallable, Category = "Market")
		void executeMarketInteractions();
	UFUNCTION(BlueprintCallable, Category = "Market")
		void executeBuildingProduction();

	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		void calculateStatus(TArray<class AActor*> CommandControllers, TArray<class AActor*> TownControllers);
	UFUNCTION(BlueprintCallable, Category = "Contracts")
		void generateEliminationContract(TArray<class ACommandUnitControl*>& CommandControllers, TArray<class ATownControl*>& TownControllers);
	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		float getFirepower();
	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		float getWealth();
	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		float getSupremacy();
	UFUNCTION(BlueprintCallable, Category = "Status Calculations")
		float getStability();

	FActorSpawnParameters buildingSpawnParameters;
	TArray <FTransform> spawnTransform;
	int32 spawnIndex;


	// buildings
	int num_houses{0};
	int num_manufactures{0};
	int num_lightmills{0};
	int num_towers{0};

	float total_titanium_production{ 0 };
	float total_light_production{ 0 };
	float total_worker_production{ 0 };
	float total_equipment_production{ 0 };

	float targetEquipmentProduction{0};
	float targetLightProduction{0};
	float targetWorkerProduction{0};

public:
	ATownControl();
};
