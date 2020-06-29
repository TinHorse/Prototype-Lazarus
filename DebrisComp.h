// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DebrisComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWNSIMULATOR_API UDebrisComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDebrisComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Health")
		int health;
	UPROPERTY(EditAnywhere, Category = "Titanium")
		int titanium_density;

public:	
	UFUNCTION(BlueprintCallable)
		int getHealth();
	UFUNCTION(BlueprintCallable)
		void decrementHealthBy(int h);
	UFUNCTION(BlueprintCallable)
		int getTitaniumDensity();
	UFUNCTION(BlueprintCallable)
		void setTitaniumDensity(int density);
};
