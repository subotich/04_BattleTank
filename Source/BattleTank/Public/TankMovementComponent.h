// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

// Forward declarations
class UTankTrack;

/**
 * Responsible for driving the tanks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	// Allows to attach "Tank Movement Component" to it (@BP Input Setup)
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveBackwards(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnLeft(float Throw);
	
private:
	// Checked best protection; Called from pathfiniding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
