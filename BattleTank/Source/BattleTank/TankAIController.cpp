// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AiTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (AiTank && PlayerTank)
	{
		// TODO Move towards player tank

		// Aim towards the player
		AiTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		AiTank->Fire(); // TODO don't fire every frame, limit firing rate
	}

}
