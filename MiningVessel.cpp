// Fill out your copyright notice in the Description page of Project Settings.

#include "MiningVessel.h"
#include "CommandUnitControl.h"
#include "BaseUnitController.h"
#include "Unit.h"

AMiningVessel::AMiningVessel() {
	faction = EFactionEnum::Blackcoats;
}

void AMiningVessel::setFactionForArmy(TEnumAsByte<EFactionEnum> value)
{
	faction = value;
	if (ACommandUnitControl* command = Cast<ACommandUnitControl>(GetController())) {
		for (auto unit_controller : command->getUnitControllers()) {
			if (AUnit* unit = Cast<AUnit>(unit_controller->GetPawn())) {
				unit->setFaction(faction);
			}
		}
	}
}
