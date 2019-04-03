// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
/* removed during refactoring */
/* 
readed during observer pattern 
TODO challenge this
*/
#include "Tank.h" // So we can implement method OnDeath ?!
// is added so it can cast to tank ..
#include "GameFramework/Pawn.h"
#include "BattleTank.h"

/*
Depends on movement component via pathfinding system
*/
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast<ATank>(InPawn);
		if (!ensure(PossesedTank)) { return; }
		UE_LOG(LogTemp, Warning, TEXT("Tank possesed!"));
		// TODO Subscribe our local method to the tank's death event
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesedTankDeath);
	}
}

void ATankAIController::OnPossesedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Event triggered & observer received!"));
	if (!ensure(GetPawn())) { return; } //TODO remove if ok
	GetPawn()->DetachFromControllerPendingDestroy();
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

