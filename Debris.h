// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Debris.generated.h"

UCLASS()
class TOWNSIMULATOR_API ADebris : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Health")
		float health;
	
public:	
	// Sets default values for this actor's properties
	ADebris();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		float getHealth();
	UFUNCTION(BlueprintCallable)
		void mofifyHealth(float h);

	UFUNCTION(BlueprintCallable)
		float calculateDistance(FVector loc);
};
