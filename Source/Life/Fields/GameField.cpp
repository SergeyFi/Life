// Fill out your copyright notice in the Description page of Project Settings.


#include "Fields/GameField.h"

// Sets default values
AGameField::AGameField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	CellAvatars = CreateDefaultSubobject<UInstancedStaticMeshComponent>("CellAvatars");
	RootComponent = CellAvatars;
}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
	Super::BeginPlay();

	if (!CheckStartupSettings()) return;

	CreateCells();

	CreateCellBehavior();

	CreateCellGenerator();

	RenderCells();

	DelayedStart();
}

FCell* AGameField::GetCellByPosition(FPosition Position)
{
	return ULifeFunctions::GetCellByPosition(Position, Size, &Cells);
}

void AGameField::CreateCells()
{
	Cells.Reserve(Size * Size * Size);

	for (auto X = 0; X < Size; ++X)
	{
		for (auto Y = 0; Y < Size; ++Y)
		{
			for (auto Z = 0; Z < Size; ++Z)
			{
				Cells.Add({FPosition{X, Y, Z}});	
			}
		}
	}
}

void AGameField::RenderCells()
{
	CellAvatars->ClearInstances();
	
	for (auto& Cell : Cells)
	{
		if (Cell.bAlive && Cell.FriendsVon != 6)
		{
			FTransform CellTransform;
			CellTransform.SetLocation
			({Cell.Position.X * DimensionScale, Cell.Position.Y * DimensionScale, Cell.Position.Z * DimensionScale});
		
			CellAvatars->AddInstance(CellTransform);
		}
	}
}

void AGameField::AssignFriendsCount(FCell& Cell)
{
	Cell.Friends = 0;
	
	for (auto X : {-1, 0, 1})
	{
		for (auto Y : {-1, 0, 1})
		{
			for (auto Z : {-1, 0, 1})
			{
				auto FriendCell = GetCellByPosition(Cell.Position + FPosition{X, Y, Z});

				if (FriendCell && FriendCell->bAlive)
				{
					Cell.Friends += 1;
				}
			}
		}
	}

	if (Cell.bAlive)
	{
		Cell.Friends -= 1;
	}

	Cell.FriendsVon = 0;
	for (auto Pos : {FPosition{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}})
	{
		auto FriendCell = GetCellByPosition(Cell.Position + Pos);

		if (FriendCell && FriendCell->bAlive)
		{
			Cell.FriendsVon += 1;
		}
	}
}

void AGameField::StartSimulation()
{
	SetActorTickEnabled(true);
}

void AGameField::CalcFriends()
{
	for (auto& Cell : Cells)
	{
		AssignFriendsCount(Cell);
	}
}

void AGameField::ApplyBehavior()
{
	if (!bStepMode)
	{
		for (auto& Cell : Cells)
		{
			CellBehavior->ApplyBehavior(Cell);
		}
	}
	else
	{
		if (CurrentStep >= Cells.Num())
		{
			CurrentStep = 0;
		}
		
		CellBehavior->ApplyBehavior(Cells[CurrentStep]);
		
		++CurrentStep;
	}
}

void AGameField::CreateCellGenerator()
{
	if (!CellGenerator && CellGeneratorClass)
	{
		CellGenerator = NewObject<UCellGenerator>(this, CellGeneratorClass);
	}

	if (CellGenerator)
	{
		CellGenerator->Init(&Cells, Size);
		CellGenerator->GenerateCells();
	}
}

void AGameField::CreateCellBehavior()
{
	CellBehavior = NewObject<UCellBehavior>(this, CellBehaviorClass);

	CellBehavior->Init(&Cells, Size);
}

bool AGameField::CheckStartupSettings()
{
	return CellBehaviorClass && Size > 0 && DimensionScale > 0 && CellGeneratorClass;
}

void AGameField::DelayedStart()
{
	FTimerHandle SimStartTimer;
	GetWorld()->GetTimerManager().SetTimer
	(SimStartTimer, this, &AGameField::StartSimulation, PrimaryActorTick.TickInterval, false, PrimaryActorTick.TickInterval);
}

// Called every frame
void AGameField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CalcFriends();

	ApplyBehavior();

	RenderCells();
}
