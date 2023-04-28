// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "SortieCharacterBase.generated.h"

//forward declaration
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class SORTIE_API ASortieCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASortieCharacterBase();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USpringArmComponent* SpringArmComp;

	//#region Player Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputMappingContext* PlayerMappingContext; //let's forward declare this because it's a pointer

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MoveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MoveRightAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* AimAction;

	bool IsFiring = false;
	bool IsAiming = false;
	
	void MoveForward(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Fire();
	void StopFire();
	void Aim();
	void StopAim();
	//#endregion

	//#region Terrain Editing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Terrain Editing")
	float LineTraceDistance = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Terrain Editing")
	float SphereRadius = 1.f;

	//Check the scale of the terrain as well
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Terrain Editing")
	float BrushForce = -1.f;

	void EditTerrain(const bool Add, bool ToggleAction);
	//#endregion
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	//Check the size of the terrain as well
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="View Helper")
	float MaxViewDistance = 100.f;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
