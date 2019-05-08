// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

/**
 * Hold barrel's property and Elevate method
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* TankBarrelToSet, UTankTurret* TankTurretToSet);

	// Appears in the blueprint as function
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	// Appears in the blueprint as function
	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

	void AimAt(FVector HitLocation);

	EFiringState GetFirinigState() const;

private:
	// Sets default values for this component's properties (Constructor can be private)
	UTankAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 8000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 RoundsLeft = 3;

	double LastFireTime = 0;

	FVector AimDirection;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
};
