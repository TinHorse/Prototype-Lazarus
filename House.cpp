// Fill out your copyright notice in the Description page of Project Settings.

#include "House.h"
#include "Inventory.h"
#include "Market.h"

AHouse::AHouse()
{
	labour = 1;
	max_labour = 1;
	output_per_labour = 0.2;
	input_per_labour = 0.5;
	target_labour = 0;
	max_output = max_labour * output_per_labour;
}

float AHouse::calculateInput(float target_output)
{
	if (target_output > max_output) {
		target_output = max_output;
	}
	//UE_LOG(LogTemp, Warning, TEXT("house target_output %f"), target_output);
	return input_demand = (target_output * input_per_labour);
}

void AHouse::produce(UMarket * market, float num_cycles)
{
	float input_resource = ((input_demand) / num_cycles);
	//UE_LOG(LogTemp, Warning, TEXT("house input_demand %f"), input_demand);
	if (input_resource > market->light_threshold) {
		input_resource = market->light_threshold;
	}

	efficiency = 0;
	if (input_demand > 0) {
		efficiency = input_resource / (input_demand / num_cycles);
	}
	//UE_LOG(LogTemp, Warning, TEXT("coefficient %f"), coefficient);
	float input = (-efficiency * labour * input_per_labour);
	market->addLight(input);
	
	output = (efficiency * labour * output_per_labour);
	market->addLabour(output + 0.1f);

	//UE_LOG(LogTemp, Warning, TEXT("efficiency %f"), efficiency);
	//UE_LOG(LogTemp, Warning, TEXT("input_resource %f"), input_resource);
	//UE_LOG(LogTemp, Warning, TEXT("titanium_threshold %f"), market->titanium_threshold);
	//UE_LOG(LogTemp, Warning, TEXT("coefficient %f"), coefficient);
	//UE_LOG(LogTemp, Warning, TEXT("output %f"), output);


}

void AHouse::interactWithMarket(UMarket * market)
{
	float target = market->getLabourDemand();
	market->addLightDemand(calculateInput(target));
}


