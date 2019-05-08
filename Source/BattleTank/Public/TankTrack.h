// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

// Forward Declaration
class ASprungWheel;

/**
 * Tank track is used to set maximum driving force and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max force per track in Newtons: assume 40t tank and 1g acceleration
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000;

	void DriveTrack(float CurrentThrottle);

private:
	UTankTrack();

	TArray<ASprungWheel*> GetWheels() const;
};
