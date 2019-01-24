// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not possesing AI tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possesd %s"), *(ControlledTank->GetName()));
	}

}
