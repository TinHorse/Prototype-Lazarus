// Fill out your copyright notice in the Description page of Project Settings.

#include "ContractElimination.h"

bool UContractElimination::checkContractCondition() {
	if (target != nullptr) {
		return false;
	}
	else {
		return true;
	}
}

