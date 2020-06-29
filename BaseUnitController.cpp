// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseUnitController.h"

void ABaseUnitController::setCommandingUnit(ACommandUnitControl * command)
{
	commandingUnit = command;
}

ACommandUnitControl * ABaseUnitController::getCommandingUnit()
{
	return commandingUnit;
}

float ABaseUnitController::getFirepower()
{
	return firepower;
}
