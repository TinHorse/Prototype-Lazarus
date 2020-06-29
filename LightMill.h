// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "LightMill.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API ALightMill : public ABuilding
{
	GENERATED_BODY()
	
public:
	ALightMill();
	void produce(class UMarket * market, float num_cycles) override;
	void interactWithMarket(class UMarket* market) override;
	
};
