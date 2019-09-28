// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	physicsHandle = FindComponentByClass<UPhysicsHandleComponent>();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::JumpPress);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMainCharacter::JumpPress);
	PlayerInputComponent->BindAxis("Horizontal", this, &AMainCharacter::Horizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &AMainCharacter::Vertical);
	PlayerInputComponent->BindAxis("Rotate", this, &AMainCharacter::Rotate);
	PlayerInputComponent->BindAxis("RotateCamera", this, &AMainCharacter::RotateCamera);
}

FHitResult AMainCharacter::ObjectToGrab()
{
	FHitResult hit;
	FVector direction = GetActorLocation();
	FVector forward = GetActorForwardVector();
	GetWorld()->LineTraceSingleByChannel(hit, direction, direction + forward * 200.f, ECollisionChannel::ECC_PhysicsBody, FCollisionQueryParams(FName(TEXT("")), false, this));
	return hit;
}

void AMainCharacter::JumpPress()
{
	bPressedJump = true;
}

void AMainCharacter::JumpRelease()
{
	bPressedJump = false;
}

void AMainCharacter::Vertical(float axis)
{
	AddMovementInput(GetActorForwardVector(), axis * speed);
}

void AMainCharacter::Horizontal(float axis)
{
	AddMovementInput(GetActorRightVector(), axis * speed);
}

void AMainCharacter::Rotate(float axis)
{
	AddControllerYawInput(axis);
}

void AMainCharacter::RotateCamera(float axis)
{
	AddControllerPitchInput(axis);
}

bool AMainCharacter::isResultValid(FHitResult hit)
{
	if (hit.GetActor()) return true;
	return false;
}