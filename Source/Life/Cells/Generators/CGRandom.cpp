// Fill out your copyright notice in the Description page of Project Settings.


#include "CGRandom.h"

void UCGRandom::GenerateCells()
{
	for (auto& Cell : *Cells)
	{
		if (FMath::RandRange(0.0f, 1.0f) <= Probability)
		{
			Cell.bAlive = true;
		}
	}
}
