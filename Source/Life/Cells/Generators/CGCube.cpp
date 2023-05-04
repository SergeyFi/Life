// Fill out your copyright notice in the Description page of Project Settings.


#include "CGCube.h"

void UCGCube::GenerateCells()
{
	for (auto X = 0; X < SizeX; ++X)
	{
		for (auto Y = 0; Y < SizeY; ++Y)
		{
			for (auto Z = 0; Z < SizeZ; ++Z)
			{
				GetCellByPosition(FPosition{X, Y, Z} + Size / 2)->bAlive = true;
			}
		}
	}
}
