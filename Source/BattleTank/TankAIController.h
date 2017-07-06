// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank_base.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATank_base* GetControlledTank() const;

	virtual void BeginPlay() override;

	ATank_base* FindPlayerControlledTank() const;
	virtual void Tick(float DeltaSeconds) override;
	
};
