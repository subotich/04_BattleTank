// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//Forward Declarations
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATank* AiTank = nullptr;

	ATank* PlayerTank = nullptr;

	// How close can AI tank get
	float AcceptanceRadius = 3000;

};
