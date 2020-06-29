// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseUnitController.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API ABaseUnitController : public AAIController
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Command")
		class ACommandUnitControl* commandingUnit;
	UPROPERTY(EditAnywhere, Category = "Command")
		float firepower;
public:
	UFUNCTION(BlueprintCallable, Category = "Command")
		void setCommandingUnit(class ACommandUnitControl* command);
	UFUNCTION(BlueprintCallable, Category = "Command")
		ACommandUnitControl* getCommandingUnit();
	UFUNCTION(BlueprintCallable, Category = "Command")
		float getFirepower();
};
