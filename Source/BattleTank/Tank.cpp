// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("ClockWising", this, &ATank::TurnRight);
	InputComponent->BindAxis("CounterWising", this, &ATank::TurnLeft);
	InputComponent->BindAxis("TankRotation", this, &ATank::TankTurnRight);
	InputComponent->BindAxis("TankMovement", this, &ATank::MoveForward);
	InputComponent->BindAxis("BarrelRotation", this, &ATank::BarrelRotation);
}

void ATank::TurnLeft(float speed)
{
	Turret->AddRelativeRotation(FRotator(0.f,speed,0.f));
}
void ATank::TurnRight(float speed)
{
	Turret->AddRelativeRotation(FRotator(0.f, speed, 0.f));
}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	Turret = TurretFromBP;
}
void ATank::SetBarrelChildActor(UChildActorComponent* BarrelFromBP)
{
	Barrel = BarrelFromBP;
}
void ATank::SetTankChildActor(UChildActorComponent* TankFromBP)
{
	Tank = TankFromBP;
}
void ATank::TankTurnRight(float speed)
{
	if (!Tank) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds*speed*RotationSpeed;
	Tank->AddRelativeRotation(FRotator(0.f, speed, 0.f));
}
void ATank::MoveForward(float speed)
{
	if (!Tank) { return; }
	float distance = GetWorld()->DeltaTimeSeconds*speed*MoveSpeed;
	Tank->AddRelativeLocation(Tank->GetForwardVector()*distance);
}

void ATank::BarrelRotation(float speed)
{
	if (!Barrel) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds*speed*RotationSpeed;
	Barrel->AddRelativeRotation(FRotator(speed, 0.0f, 0.f));
}
