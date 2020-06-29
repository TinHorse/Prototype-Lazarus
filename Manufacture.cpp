// Fill out your copyright notice in the Description page of Project Settings.

#include "Manufacture.h"
#include "Market.h"

AManufacture::AManufacture() 
{
	max_labour = 30;
	output_per_labour = 2;
	input_per_labour = 5;

	max_output = max_labour * output_per_labour;
}

void AManufacture::produce(UMarket * market, float num_cycles)
{
	float input_resource = input_demand / num_cycles;
	if (input_resource > market->titanium_threshold) {
		input_resource = market->titanium_threshold;
	}

	efficiency = 0;
	if (input_demand > 0) {
		efficiency = input_resource / (input_demand / num_cycles);
	}
	auto input = (-efficiency * labour * input_per_labour);
	market->addTitanium(input);

	output = (efficiency * labour * output_per_labour);
	market->addEquipment(output);
}

void AManufacture::interactWithMarket(UMarket * market)
{
	float target = market->getEquipmentDemand();
	market->addLabourDemand(calculateLabourDemand(target));
	addLabour(market, market->labour_threshold);
	market->addTitaniumDemand(calculateInputDemand());
}
