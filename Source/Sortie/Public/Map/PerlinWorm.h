// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MCChunk.h"

/**
 * 
 */
class SORTIE_API PerlinWorm
{
public:
	PerlinWorm();
	PerlinWorm(int Dur, int Rad, float P, float Y, float R);
	~PerlinWorm();

	int Duration;
	int Radius;
	
	float WormPitchMax = 135.f;
	float WormYawMax = 135.f;
	float WormRollMax = 135.f;

	float WormPitch;
	float WormYaw;
	float WormRoll;

	void Wormify(AMCChunk* Chunk, const FVector& Loc, int Time = 0);
	void RadialAddGrids(AMCChunk* Chunk, int Range, const FVector& Origin) const;
};
