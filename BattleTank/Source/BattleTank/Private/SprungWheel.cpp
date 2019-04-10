// Fill out your copyright notice in the Description page of Project Settings.


#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "BattleTank.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TankSpringConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Tank Spring Constraint"));
	SetRootComponent(TankSpringConstraint);

	/* removed */
	//Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	//Mass->SetupAttachment(MassWheelConstraint);
	
	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axle"));
	Axle->SetupAttachment(TankSpringConstraint);

	AxleWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Axle Wheel Constraint"));
	AxleWheelConstraint->SetupAttachment(Axle);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axle);

}

void ASprungWheel::AddDrivingForce(float ForceMagnitude)
{
	Wheel->AddForce(Axle->GetForwardVector() * ForceMagnitude);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraint();

}

void ASprungWheel::SetupConstraint()
{
	UE_LOG(LogTemp, Warning, TEXT("SetupConstraint started"));
	if (!GetAttachParentActor()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No GetAttachParentActor"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not null, %s"), *GetAttachParentActor()->GetName());
	}
	
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot)
	{
		UE_LOG(LogTemp, Warning, TEXT("No BodyRoot"));
		return;
	}
	TankSpringConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axle, NAME_None);
	AxleWheelConstraint->SetConstrainedComponents(Axle, NAME_None, Wheel, NAME_None);
}