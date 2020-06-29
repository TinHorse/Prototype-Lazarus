// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprfloatSpawnableComponent) )
class TOWNSIMULATOR_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Resource")
		float titanium{ 0 };
	UPROPERTY(EditAnywhere, Category = "Resource")
		float labour{ 0 };
	UPROPERTY(EditAnywhere, Category = "Resource")
		float equipment{ 0 };
	UPROPERTY(EditAnywhere, Category = "Resource")
		float light{ 0 };
	UPROPERTY(EditAnywhere, Category = "Resource")
		float light_powder{ 0 };
	UPROPERTY(EditAnywhere, Category = "Resource")
		float books{ 0 };

	UPROPERTY(EditAnywhere, Category = "Demand")
		float titanium_demand{ 0 };
	UPROPERTY(EditAnywhere, Category = "Demand")
		float labour_demand{ 0 };
	UPROPERTY(EditAnywhere, Category = "Demand")
		float equipment_demand{ 0 };
	UPROPERTY(EditAnywhere, Category = "Demand")
		float light_demand{ 0 };
	UPROPERTY(EditAnywhere, Category = "Demand")
		float light_powder_demand{ 0 };
	UPROPERTY(EditAnywhere, Category = "Demand")
		float books_demand{ 0 };


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float getTitanium();
	float getLabour();
	float getEquipment();
	float getLight();
	float getLightPowder();
	float getBooks();

	float getTitaniumDemand();
	float getLabourDemand();
	float getEquipmentDemand();
	float getLightDemand();
	float getLightPowderDemand();
	float getBooksDemand();

	UFUNCTION(BlueprintCallable, Category = "Titanium")
		void addTitanium(float tit);
	void addLabour(float lab);
	void addEquipment(float equ);
	void addLight(float lig);
	void addLightPowder(float ligpow);
	void addBooks(float book);

	virtual void addTitaniumDemand(float tit);
	virtual void addLabourDemand(float lab);
	virtual void addEquipmentDemand(float equ);
	virtual void addLightDemand(float lig);
	virtual void addLightPowderDemand(float ligpow);
	virtual void addBooksDemand(float book);

	void setTitaniumDemand(float tit);
	void setLabourDemand(float lab);
	void setEquipmentDemand(float equ);
	void setLightDemand(float lig);
	void setLightPowderDemand(float ligpow);
	void setBooksDemand(float book);

	void setTitanium(float tit);
	void setLabour(float lab);
	void setEquipment(float equ);
	void setLight(float lig);
	void setLightPowder(float ligpow);
	void setBooks(float book);

	void clearAllDemands();
	

		
};
