// Fill out your copyright notice in the Description page of Project Settings.

#include "Contract.h"

void UContract::setupContract(AActor * _target, AActor * town_controller_issuer, float _payment, float _risk)
{
	target = _target;
	contract_issuer = town_controller_issuer;
	payment = _payment;
	risk = _risk;
}

bool UContract::checkContractCondition()
{
	return false;
}
