// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CellGenerator.h"
#include "CGRandom.generated.h"

/**
 * 
 */
UCLASS()
class LIFE_API UCGRandom : public UCellGenerator
{
	GENERATED_BODY()

public:

	virtual void GenerateCells() override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Random")
	float Probability = 1.0f;
};
