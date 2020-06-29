// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "STRUCTS.h"
#include "MiningVessel.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API AMiningVessel : public AUnit
{
	GENERATED_BODY()
protected:

public:
	AMiningVessel();
	UFUNCTION(BlueprintCallable, Category = "Factions")
		void setFactionForArmy(TEnumAsByte<EFactionEnum> value);
};
