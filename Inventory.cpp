// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UInventory::getTitanium()
{
	return titanium;
}

float UInventory::getLabour()
{
	return labour;
}

float UInventory::getEquipment()
{
	return equipment;
}

float UInventory::getLight()
{
	return light;
}

float UInventory::getLightPowder()
{
	return light_powder;
}

float UInventory::getBooks()
{
	return books;
}




float UInventory::getTitaniumDemand()
{
	return titanium_demand;
}

float UInventory::getLabourDemand()
{
	return labour_demand;
}

float UInventory::getEquipmentDemand()
{
	return equipment_demand;
}

float UInventory::getLightDemand()
{
	return light_demand;
}

float UInventory::getLightPowderDemand()
{
	return light_powder_demand;
}

float UInventory::getBooksDemand()
{
	return books_demand;
}



void UInventory::addTitanium(float tit)
{
	titanium += tit;
	titanium = FMath::Clamp(titanium, 0.f, 100000.f);
}

void UInventory::addLabour(float lab)
{
	labour += lab;
	labour = FMath::Clamp(labour, 0.f, 100000.f);
}

void UInventory::addEquipment(float equ)
{
	equipment += equ;
	equipment = FMath::Clamp(equipment, 0.f, 100000.f);
}

void UInventory::addLight(float lig)
{
	light += lig;
	light = FMath::Clamp(light, 0.f, 100000.f);
}

void UInventory::addLightPowder(float ligpow)
{
	light_powder += ligpow;
	light_powder = FMath::Clamp(light_powder, 0.f, 100000.f);
}

void UInventory::addBooks(float book)
{
	books += book;
	books = FMath::Clamp(books, 0.f, 100000.f);
}



void UInventory::addTitaniumDemand(float tit)
{
	titanium_demand += tit;
	titanium_demand = FMath::Clamp(titanium_demand, 0.f, 100000.f);
}

void UInventory::addLabourDemand(float lab)
{
	labour_demand += lab;
	labour_demand = FMath::Clamp(labour_demand, 0.f, 100000.f);
}

void UInventory::addEquipmentDemand(float equ)
{
	equipment_demand += equ;
	equipment_demand = FMath::Clamp(equipment_demand, 0.f, 100000.f);
}

void UInventory::addLightDemand(float lig)
{
	light_demand += lig;
	light_demand = FMath::Clamp(light_demand, 0.f, 100000.f);
}

void UInventory::addLightPowderDemand(float ligpow)
{
	light_powder_demand += ligpow;
	light_powder_demand = FMath::Clamp(light_powder_demand, 0.f, 100000.f);
}

void UInventory::addBooksDemand(float book)
{
	books_demand += book;
	books_demand = FMath::Clamp(books_demand, 0.f, 100000.f);
}


void UInventory::setTitaniumDemand(float tit)
{
	titanium_demand = tit;
	titanium_demand = FMath::Clamp(titanium_demand, 0.f, 100000.f);
}

void UInventory::setLabourDemand(float lab)
{
	labour_demand = lab;
	labour_demand = FMath::Clamp(labour_demand, 0.f, 100000.f);
}

void UInventory::setEquipmentDemand(float equ)
{
	equipment_demand = equ;
	equipment_demand = FMath::Clamp(equipment_demand, 0.f, 100000.f);
}

void UInventory::setLightDemand(float lig)
{
	light_demand = lig;
	light_demand = FMath::Clamp(light_demand, 0.f, 100000.f);
}

void UInventory::setLightPowderDemand(float ligpow)
{
	light_powder_demand = ligpow;
	light_powder_demand = FMath::Clamp(light_powder_demand, 0.f, 100000.f);
}

void UInventory::setBooksDemand(float book)
{
	books_demand = book;
	books_demand = FMath::Clamp(books_demand, 0.f, 100000.f);
}



void UInventory::setTitanium(float tit)
{
	titanium = tit;
	titanium = FMath::Clamp(titanium, 0.f, 100000.f);
}

void UInventory::setLabour(float lab)
{
	labour = lab;
	labour = FMath::Clamp(labour, 0.f, 100000.f);
}

void UInventory::setEquipment(float equ)
{
	equipment = equ;
	equipment = FMath::Clamp(equipment, 0.f, 100000.f);
}

void UInventory::setLight(float lig)
{
	light = lig;
	light = FMath::Clamp(light, 0.f, 100000.f);
}

void UInventory::setLightPowder(float ligpow)
{
	light_powder = ligpow;
	light_powder = FMath::Clamp(light_powder, 0.f, 100000.f);
}

void UInventory::setBooks(float book)
{
	books = book;
	books = FMath::Clamp(books, 0.f, 100000.f);
}

void UInventory::clearAllDemands()
{
	titanium_demand = 0;
	labour_demand = 0;
	equipment_demand = 0;
	light_demand = 0;
	light_powder_demand = 0;
	books_demand = 0;
}


