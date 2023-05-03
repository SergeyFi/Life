// Fill out your copyright notice in the Description page of Project Settings.


#include "CellGenerator.h"

void UCellGenerator::Init(TArray<FCell>* InitCells, int32 InitSize)
{
	Cells = InitCells;
	Size = InitSize;
}

void UCellGenerator::GenerateCells()
{
	
}

FCell* UCellGenerator::GetCellByPosition(const FPosition& Position)
{
	return ULifeFunctions::GetCellByPosition(Position, Size, Cells);
}
