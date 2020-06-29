// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Diplomacy.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprfloatSpawnableComponent) )
class TOWNSIMULATOR_API UDiplomacy : public UActorComponent
{
	GENERATED_BODY()
protected:
	//UPROPERTY(EditAnywhere, Category = "Entities in Area")
		//TArray<class AMiningVessel*> contractors_in_area;
	//UPROPERTY(EditAnywhere, Category = "Entities in Area")
		//TArray<class ATown*> towns_in_area;
	UPROPERTY(EditAnywhere, Category = "Range")
		float scanRadius{2000};
	UPROPERTY(EditAnywhere, Category = "Factions")
		TMap<int, int> faction_relations;
	

public:	
	// Sets default values for this component's properties
	UDiplomacy();
	//UFUNCTION(BlueprintCallable, Category = "Entities in Area")
		//TArray<class AMiningVessel*>& getMiners();
	//UFUNCTION(BlueprintCallable, Category = "Entities in Area")
		//TArray<class ATown*>& getTowns();
	UFUNCTION(BlueprintCallable, Category = "Radius")
		float getScanRadius();
	UFUNCTION(BlueprintCallable, Category = "Radius")
		void setScanRadius(float rad);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
