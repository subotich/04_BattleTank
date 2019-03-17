// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

/* removed during refactoring */
 //Forward Declarations
//class UTankBarrel;
//class AProjectile;
//class UTankTurret;
//class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	/* removed during refactoring */
	/*
	
	UFUNCTION(BlueprintCallable, Category = "Setup")			// Appears in the blueprint as function
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")			// Appears in the blueprint as function
	void SetTurretReference(UTankTurret* TurretToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Firing")			// Appears in the blueprint as function
	void Fire();
	
	UPROPERTY(BlueprintReadOnly)								// Appears in the blueprint
	UTankMovementComponent* TankMovementComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)								// Appears in the blueprint
	UTankAimingComponent* TankAimingComponent = nullptr;

	*/

private:	
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/* removed during refactoring */
	/*
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;	// TODO remove

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// TODO remove once firing is moved to aiming componenet
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	*/

};
