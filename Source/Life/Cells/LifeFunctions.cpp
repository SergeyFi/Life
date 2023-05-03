// Fill out your copyright notice in the Description page of Project Settings.


#include "LifeFunctions.h"

FCell* ULifeFunctions::GetCellByPosition(const FPosition& Position, const int32 Size, TArray<FCell>* Cells)
{
	auto Index = Position.X * Size * Size + Position.Y * Size + Position.Z;

	if (Index >= 0 && Index < Cells->Num())
	{
		return &(*Cells)[Index];
	}

	return nullptr;
}
