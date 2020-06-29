// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "House.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API AHouse : public ABuilding
{
	GENERATED_BODY()
protected:
	
public:
	AHouse();
	void produce(class UMarket * market, float num_cycles) override;
	void interactWithMarket(class UMarket* market) override;

	float calculateInput(float target_output);
};
