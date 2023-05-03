// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cells/Cell.h"
#include "Cells/LifeFunctions.h"
#include "UObject/Object.h"
#include "CellGenerator.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew, Abstract, HideDropdown)
class LIFE_API UCellGenerator : public UObject
{
	GENERATED_BODY()

public:

	void Init(TArray<FCell>* InitCells, int32 InitSize);

	virtual void GenerateCells();

protected:

	TArray<FCell>* Cells;

	int32 Size;

	FCell* GetCellByPosition(const FPosition& Position);
};
