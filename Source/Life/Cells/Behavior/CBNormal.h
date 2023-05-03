// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CellBehavior.h"
#include "CBNormal.generated.h"

/**
 * 
 */
UCLASS()
class LIFE_API UCBNormal : public UCellBehavior
{
	GENERATED_BODY()

public:

	virtual void ApplyBehavior(FCell& Cell) override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Behavior")
	int32 FriendsMin = 5;

	UPROPERTY(EditDefaultsOnly, Category = "Behavior")
	int32 FriendsMax = 6;

	UPROPERTY(EditDefaultsOnly, Category = "Behavior")
	int32 FriendsToAlive = 4;
};
