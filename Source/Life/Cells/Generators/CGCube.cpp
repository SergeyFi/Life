// Fill out your copyright notice in the Description page of Project Settings.


#include "CGCube.h"

void UCGCube::GenerateCells()
{
	for (auto X = 0; X < 2; ++X)
	{
		for (auto Y = 0; Y < 2; ++Y)
		{
			for (auto Z = 0; Z < 2; ++Z)
			{
				GetCellByPosition(FPosition{X, Y, Z} + Size / 2)->bAlive = true;
			}
		}
	}
}
