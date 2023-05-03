// Fill out your copyright notice in the Description page of Project Settings.


#include "CellBehavior.h"

void UCellBehavior::Init(TArray<FCell>* InitCells,  int32 InitFieldSize)
{
	Cells = InitCells;
	FieldSize = InitFieldSize;
}

void UCellBehavior::ApplyBehavior(FCell& Cell)
{

}
