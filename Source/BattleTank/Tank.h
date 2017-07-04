// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void TurnLeft(float speed);
	void TurnRight(float speed);
	void TankTurnLeft(float speed);
	void TankTurnRight(float speed);
	void MoveForward(float speed);
	void MoveBack(float speed);
	void BarrelRotation(float speed);
	UChildActorComponent* Turret;
	UChildActorComponent* Barrel;
	UChildActorComponent* Tank;
	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent* TurretFromBP);
	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent* BarrelFromBP);
	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTankChildActor(UChildActorComponent* TankFromBP);
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 120.f;
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 120.f;
};
