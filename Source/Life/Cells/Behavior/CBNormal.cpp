// Fill out your copyright notice in the Description page of Project Settings.


#include "CBNormal.h"

void UCBNormal::ApplyBehavior(FCell& Cell)
{
	if (Cell.bAlive)
	{
		if (Cell.Friends < FriendsMin || Cell.Friends > FriendsMax)
		{
			Cell.bAlive = false;
		}
	}
	else
	{
		if (Cell.Friends == FriendsToAlive)
		{
			Cell.bAlive = true;
		}
	}
}
