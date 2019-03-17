// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
/* removed during refactoring */
//#include "TankAimingComponent.h"
//#include "Projectile.h"
//#include "TankBarrel.h"
#include "BattleTank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/* removed during refactoring */
	/*

	// No need to protect pointers as added at construction
	// These appear under the tank's BP as "Inherited" components
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	
	*/
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();		// Needed for BP Begin Play to run
	
	/* removed during refactoring */
	/*

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();

	*/
}

/* removed during refactoring */
/*
// Tell controlled tank to aim at this point
void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
*/

/* removed during refactoring */
/*

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	//UE_LOG(LogTemp, Warning, TEXT("Fire!"));
	if (isReloaded)
	{
		// Spawn a projectile on a socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

*/
