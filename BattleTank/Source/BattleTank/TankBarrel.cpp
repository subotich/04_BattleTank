// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTank.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the right amount this frame
	// Given the max elevation speed and frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevated at speed %f"), DegreesPerSecond);
}
