// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cell.h"
#include "UObject/Object.h"
#include "LifeFunctions.generated.h"

/**
 * 
 */
UCLASS()
class LIFE_API ULifeFunctions : public UObject
{
	GENERATED_BODY()

public:

	static FCell* GetCellByPosition(const FPosition& Position, int32 Size, TArray<FCell>* Cells);
};
