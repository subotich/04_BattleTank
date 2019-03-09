// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "BattleTank.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO pervent double speed?
	// TODO fix forces and/or collisions: tank goes crazy when speeding and changing directions
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO pervent double speed?
	// TODO fix forces and/or collisions: tank goes crazy when speeding and changing directions
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
	// TODO pervent double speed?
	// TODO fix forces and/or collisions: tank goes crazy when speeding and changing directions
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing functionality 
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s is vectoring to %s"), *TankName, *MoveVelocityString);

}
