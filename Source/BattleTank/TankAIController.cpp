// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	auto ControlledTank = FindPlayerControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not finding a player's tank"));
	}
	UE_LOG(LogTemp, Warning, TEXT("AIController finded player's tank£º%s"), *(ControlledTank->GetName()));
}
void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetControlledTank())
	{
		GetControlledTank()->AimAt(FindPlayerControlledTank()->GetActorLocation());
	}
}
ATank_base* ATankAIController::GetControlledTank() const
{
	return Cast<ATank_base>(GetPawn());
}
ATank_base* ATankAIController::FindPlayerControlledTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank_base>(PlayerTank);
}


