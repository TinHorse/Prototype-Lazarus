// Fill out your copyright notice in the Description page of Project Settings.

#include "Market.h"
#include "Building.h"
#include "House.h"
#include "Manufacture.h"

UMarket::UMarket() 
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMarket::normalizeDemands()
{
	
	addTitaniumDemand(-titanium / 3);
	addLabourDemand(-labour / 3);
	addEquipmentDemand(-equipment / 3);
	addLightDemand(-light / 3);
	addLightPowderDemand(-light_powder / 3);
	addBooksDemand(-books / 3);
	

	if (titanium_demand < 0) {
		titanium_demand = 0;
	}
	else {
		titanium_demand /= 2;
	}

	if (labour_demand < 0) {
		labour_demand = 0;
	}
	else {
		labour_demand /= 2;
	}

	if (equipment_demand < 0) {
		equipment_demand = 0;
	}
	else {
		equipment_demand /= 2;
	}

	if (light_demand < 0) {
		light_demand = 0;
	}
	else {
		light_demand /= 2;
	}

	if (light_powder_demand < 0) {
		light_powder_demand = 0;
	}
	else {
		light_powder_demand /= 2;
	}

	if (books_demand < 0) {
		books_demand = 0;
	}
	else {
		books_demand /= 2;
	}
}

void UMarket::setThresholds()
{

	if (num_titanium_demands) {
		titanium_threshold = titanium / num_titanium_demands;
	}
	else {
		titanium_threshold = 0;
	}
	if (num_labour_demands) {
		labour_threshold = labour / num_labour_demands;
	}
	else {
		labour_threshold = 0;
	}
	if (num_equipment_demands) {
		equipment_threshold = equipment / num_equipment_demands;
	}
	else {
		equipment_threshold = 0;
	}
	if (num_light_demands) {
		light_threshold = light / num_light_demands;
	}
	else {
		light_threshold = 0;
	}
	if (num_light_powder_demands) {
		light_powder_threshold = light_powder / num_light_powder_demands;
	}
	else {
		light_powder_threshold = 0;
	}
	if (num_books_demands) {
		books_threshold = books / num_books_demands;
	}
	else {
		books_threshold = 0;
	}

	num_titanium_demands = 0;
	num_labour_demands = 0;
	num_equipment_demands = 0;
	num_light_demands = 0;
	num_light_powder_demands = 0;
	num_books_demands = 0;
}




void UMarket::addTitaniumDemand(float val)
{
		titanium_demand += val;
		num_titanium_demands++;
		titanium_demand = FMath::Clamp(titanium_demand, 0.f, 100000.f);
}

void UMarket::addLabourDemand(float val)
{
	labour_demand += val;
	labour_demand = FMath::Clamp(labour_demand, 0.f, 100000.f);
	num_labour_demands++;
}

void UMarket::addEquipmentDemand(float val)
{
		equipment_demand += val;
		num_equipment_demands++;
		equipment_demand = FMath::Clamp(equipment_demand, 0.f, 100000.f);
}

void UMarket::addLightDemand(float val)
{
		light_demand += val;
		num_light_demands++;
		light_demand = FMath::Clamp(light_demand, 0.f, 100000.f);
}

void UMarket::addLightPowderDemand(float val)
{
		light_powder_demand += val;
		num_light_powder_demands++;
		light_powder_demand = FMath::Clamp(light_powder_demand, 0.f, 100000.f);
}

void UMarket::addBooksDemand(float val)
{
		books_demand += val;
		num_books_demands++;
		books_demand = FMath::Clamp(books_demand, 0.f, 100000.f);
}


