// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"Tank_base.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank_base* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	bool GetSightRayHitLocation(FVector& HitLocation)const;
	bool GetLookDirection(FVector2D &ScreenLocation, FVector &LookDirection) const;
	void AimTowardsCrosshair();
	bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33f;
	UPROPERTY(EditAnywhere)
	float DetectDistance = 1000000.f;
};
