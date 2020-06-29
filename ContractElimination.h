// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Contract.h"
#include "ContractElimination.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API UContractElimination : public UContract
{
	GENERATED_BODY()
protected:

public:
	bool checkContractCondition() override;
};
