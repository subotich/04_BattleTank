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
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO pervent double speed?
	// TODO fix forces and/or collisions: tank goes crazy when speeding and changing directions
}

void UTankMovementComponent::IntendMoveBackwards(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO pervent double speed?
	// TODO fix forces and/or collisions: tank goes crazy when speeding and changing directions
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO pervent double speed?
	// TODO fix forces and/or collisions: tank goes crazy when speeding and changing directions
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
	// TODO pervent double speed?
	// TODO fix forces and/or collisions: tank goes crazy when speeding and changing directions
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing functionality 
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	// TODO do the same as tunrning right, for the backwards move
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	
	// TODO don't make full turn right when angle is 270, instead turn left
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);
}
