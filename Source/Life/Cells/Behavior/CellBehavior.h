// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Cells/Cell.h"
#include "CellBehavior.generated.h"

/**
 * 
 */
UCLASS(Abstract, HideDropdown)
class LIFE_API UCellBehavior : public UObject
{
	GENERATED_BODY()

public:

	void Init(TArray<FCell>* InitCells, int32 InitFieldSize);
	
	virtual void ApplyBehavior(FCell& Cell);

private:
	
	TArray<FCell>* Cells;

	int32 FieldSize;
};
