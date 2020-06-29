// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum EFactionEnum
{
	Blackcoats 	UMETA(DisplayName = "Blackcoats"),
	Ironcasters 	UMETA(DisplayName = "Ironcasters"),
	Falcons	UMETA(DisplayName = "Falcons"),
	Freemen	UMETA(DisplayName = "Freemen")
};
