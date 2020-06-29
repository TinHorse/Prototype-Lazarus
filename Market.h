// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "Market.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API UMarket : public UInventory
{
	GENERATED_BODY()

public:
	UMarket();

	UPROPERTY(EditAnywhere, Category = "Threshold")
		float titanium_threshold{ 0 };
	UPROPERTY(EditAnywhere, Category = "Threshold")
		float labour_threshold{ 0 };
	UPROPERTY(EditAnywhere, Category = "Threshold")
		float equipment_threshold{ 0 };
	UPROPERTY(EditAnywhere, Category = "Threshold")
		float light_threshold{ 0 };
	UPROPERTY(EditAnywhere, Category = "Threshold")
		float light_powder_threshold{ 0 };
	UPROPERTY(EditAnywhere, Category = "Threshold")
		float books_threshold{ 0 };

	UPROPERTY(EditAnywhere, Category = "Num_Demands")
		float num_titanium_demands{ 0 };
	UPROPERTY(EditAnywhere, Category = "Num_Demands")
		float num_labour_demands{ 0 };
	UPROPERTY(EditAnywhere, Category = "Num_Demands")
		float num_equipment_demands{ 0 };
	UPROPERTY(EditAnywhere, Category = "Num_Demands")
		float num_light_demands{ 0 };
	UPROPERTY(EditAnywhere, Category = "Num_Demands")
		float num_light_powder_demands{ 0 };
	UPROPERTY(EditAnywhere, Category = "Num_Demands")
		float num_books_demands{ 0 };

public:
	void normalizeDemands();
	void setThresholds();

	float total_titanium_production{ 0 };
	float total_light_production{ 0 };
	float total_worker_production{ 0 };
	float total_equipment_production{ 0 };
	
	virtual void addTitaniumDemand(float val);
	virtual void addLabourDemand(float val);
	virtual void addEquipmentDemand(float val);
	virtual void addLightDemand(float val);
	virtual void addLightPowderDemand(float val);
	virtual void addBooksDemand(float val);
};
