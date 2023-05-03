// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cell.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FPosition
{
 GENERATED_BODY()

 int32 X;
 int32 Y;
 int32 Z;

 friend FPosition operator + (const FPosition& A, const FPosition& B)
 {
  return {A.X + B.X, A.Y + B.Y, A.Z + B.Z};
 }

 friend FPosition operator + (const FPosition& A, const int32& B)
 {
  return {A.X + B, A.Y + B, A.Z + B};
 }

 friend bool operator == (const FPosition& A, const FPosition& B)
 {
   return A.X == B.X && A.Y == B.Y && A.Z == B.Z; 
 }
};

USTRUCT(BlueprintType)
struct FCell
{
 GENERATED_BODY()

 FPosition Position;
 bool bAlive = false;
 bool Blocked = false;
 int32 RenderID = -1;
 int32 Friends = 0;
};