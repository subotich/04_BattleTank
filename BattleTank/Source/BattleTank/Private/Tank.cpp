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

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	UE_LOG(LogTemp, Warning, TEXT("DamageAmount=%f, DamageToApply=%i"), DamageAmount, DamageToApply);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <=0 )
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank died! Broadcasting OnDeath..."));
		OnDeath.Broadcast();
	}

	return DamageToApply;
}

float ATank::GetHealthPercentage() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

/* removed during refactoring */
/*
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();		// Needed for BP Begin Play to run

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

// Tell controlled tank to aim at this point
void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

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
