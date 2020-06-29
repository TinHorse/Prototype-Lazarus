// Fill out your copyright notice in the Description page of Project Settings.

#include "LightMill.h"
#include "Market.h"

ALightMill::ALightMill()
{
	max_labour = 50;
	output_per_labour = 0.1;
	input_per_labour = 0.5;

	max_output = max_labour * output_per_labour;
}

void ALightMill::produce(UMarket * market, float num_cycles)
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
	market->addEquipment(input);

	output = (efficiency * labour * output_per_labour);
	market->addLight(output);
	//UE_LOG(LogTemp, Warning, TEXT("%f output light mill"), output);
	//UE_LOG(LogTemp, Warning, TEXT("%f labour light mill"), labour);
}

void ALightMill::interactWithMarket(UMarket * market)
{
	float target = market->getLightDemand();
	market->addLabourDemand(calculateLabourDemand(target));
	addLabour(market, market->labour_threshold);
	market->addEquipmentDemand(calculateInputDemand());
}
