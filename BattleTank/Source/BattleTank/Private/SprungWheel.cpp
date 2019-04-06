// Fill out your copyright notice in the Description page of Project Settings.


#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "BattleTank.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass Wheel Constraint"));
	SetRootComponent(MassWheelConstraint);

	/* removed */
	//Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	//Mass->SetupAttachment(MassWheelConstraint);
	
	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	if (GetAttachParentActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not null"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Null"));
	}

}


