// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnPoint.h"
#include "BattleTank.h"

// Sets default values for this component's properties
USpawnPoint::USpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* USpawnPoint::GetSpawnedActor() const
{
	return SpawnedActor;
}

// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	SpawnedActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, GetComponentTransform());
	if (!SpawnedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("No NewActor"));
		return;
	}
	SpawnedActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	
	UGameplayStatics::FinishSpawningActor(SpawnedActor, GetComponentTransform());
}

