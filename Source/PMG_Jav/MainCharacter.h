// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class PMG_JAV_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	UPROPERTY(BlueprintReadWrite)
		float speed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Vertical(float axis);
	void Horizontal(float axis);
	void Rotate(float axis);
	void RotateCamera(float axis);
	void JumpPress();
	void JumpRelease();

	UFUNCTION(BlueprintCallable)
		FHitResult ObjectToGrab();

	UFUNCTION(BlueprintCallable)
		bool isResultValid(FHitResult hit);

	UPhysicsHandleComponent* physicsHandle;

};