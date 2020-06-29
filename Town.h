// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STRUCTS.h"
#include "Town.generated.h"

UCLASS()
class TOWNSIMULATOR_API ATown : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Component")
		UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, Category = "Faction")
		TEnumAsByte<EFactionEnum> faction;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
		void message();
	UFUNCTION(BlueprintCallable, Category = "Factions")
		void setFaction(TEnumAsByte<EFactionEnum> value);
	UFUNCTION(BlueprintCallable, Category = "Factions")
		TEnumAsByte<EFactionEnum> getFaction();
};
