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
	InputComponent->BindAction("Clockwising", IE_Pressed, this, &ATank::TurnRight);
	InputComponent->BindAction("Couterwising", IE_Pressed, this, &ATank::TurnLeft);
}

void ATank::TurnLeft()
{
	Turret->SetRelativeRotation(FRotator(0.f,-45.f,0.f));
}
void ATank::TurnRight()
{
	Turret->SetRelativeRotation(FRotator(0.f, 45.f, 0.f));
}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	Turret = TurretFromBP;
}

