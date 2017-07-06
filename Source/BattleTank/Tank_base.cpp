// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_base.h"


// Sets default values
ATank_base::ATank_base()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank_base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank_base::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank_base::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank_base::AimAt(FVector HitLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetName(), *HitLocation.ToString());
}

