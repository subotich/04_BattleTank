// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
/* removed during refactoring */
//#include "Tank.h"
#include "GameFramework/Pawn.h"
#include "BattleTank.h"

/*
Depends on movement component via pathfinding system
*/
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AiTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(AiTank && PlayerTank)) { return; }

	auto AimingComponent = AiTank->FindComponentByClass<UTankAimingComponent>();

	// Move towards player tank
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	if (AimingComponent->GetFirinigState() == EFiringState::Locked)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AI rdy 2 Fire!"));
		// Fire if ready
		AimingComponent->Fire();
	}
}

