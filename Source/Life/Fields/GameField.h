// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cells/Behavior/CellBehavior.h"
#include "Cells/LifeFunctions.h"
#include "Cells/Generators/CellGenerator.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GameField.generated.h"


UCLASS()
class LIFE_API AGameField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameField();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Field")
	int32 Size = 100;

	UPROPERTY(EditDefaultsOnly, Category = "Field")
	float DimensionScale = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Field")
	TSubclassOf<UCellBehavior> CellBehaviorClass;

	UPROPERTY(EditDefaultsOnly, Category = "Field")
	bool bStepMode;

	UPROPERTY(EditDefaultsOnly, Instanced, Category = "Field")
	UCellGenerator* CellGenerator;

	UPROPERTY(VisibleAnywhere, Category = "Field")
	UInstancedStaticMeshComponent* CellAvatars;

	FCell* GetCellByPosition(FPosition Position);

private:

	TArray<FCell> Cells;

	int32 CurrentCellIndex = 0;

	UPROPERTY()
	UCellBehavior* CellBehavior;

	int32 CurrentStep = 0;

	void CreateCells();

	void RenderCells();

	int32 GetFriendsCount(FCell& Cell);

	void StartSimulation();

	void CalcFriends();

	void ApplyBehavior();
};
