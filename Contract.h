// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Contract.generated.h"

/**
 * 
 */
UCLASS()
class TOWNSIMULATOR_API UContract : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Target")
		AActor* target;
	UPROPERTY(EditAnywhere, Category = "Specification")
		class AActor* contract_issuer;
	UPROPERTY(EditAnywhere, Category = "Specification")
		float risk;
	UPROPERTY(EditAnywhere, Category = "Specification")
		float payment;
	UPROPERTY(EditAnywhere, Category = "Specification")
		FString contract_type;

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void setupContract(AActor* _target, AActor* town_controller_issuer, float _payment, float _risk);
	UFUNCTION(BlueprintCallable, Category = "Condition Check")
		virtual bool checkContractCondition();
	
};
