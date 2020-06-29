// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"

UCLASS()
class TOWNSIMULATOR_API ABuilding : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Component")
		UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, Category = "Component")
		float firepower{ 0 };

	//UPROPERTY(EditAnywhere, Category = "Resources")
		//class UInventory* inventory;

	float max_labour;
	float max_output;
	float output_per_labour;
	float input_per_labour;
	
	float target_labour{0};
	float input_demand{0};
	float labour_demand{0};

	float output{0};
	float labour{0};
	float efficiency{1};	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UInventory* getInventory();

	virtual float calculateLabourDemand(float target_output);
	virtual void addLabour(class UMarket * market, float labour_threshold);
	virtual float calculateInputDemand();
	virtual void produce(class UMarket * market, float num_cycles);
	virtual void interactWithMarket(class UMarket* market);

	float getLabour();
	void setLabour(float lab);
	float getMaxOutput();
	float getFirepower();
};
