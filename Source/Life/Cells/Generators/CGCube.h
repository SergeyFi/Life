// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CellGenerator.h"
#include "CGCube.generated.h"

/**
 * 
 */
UCLASS()
class LIFE_API UCGCube : public UCellGenerator
{
	GENERATED_BODY()

public:

	virtual void GenerateCells() override;
};
