// Fill out your copyright notice in the Description page of Project Settings.

#include "NewAI.h"


// Sets default values
ANewAI::ANewAI()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANewAI::BeginPlay()
{
	Super::BeginPlay();
	target = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void ANewAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!target) return;

	switch (currentBehaviour)
	{
	case EAIBehaviour::FollowTarget:
		FollowTarget(DeltaTime);
		break;
	case EAIBehaviour::ObstacleAvoidance:
		ObstacleAvoidance(DeltaTime);
		break;
	}
}

void ANewAI::FollowTarget(float deltaTime)
{
	FVector dir = target->GetActorLocation() - GetActorLocation();
	FRotator rot = dir.Rotation();
	SetActorRotation(rot);

	SetActorLocation(GetActorLocation() + GetActorForwardVector()*speed*deltaTime);
}


void ANewAI::ObstacleAvoidance(float deltaTime)
{
	if (!closestObstacle)
	{
		FollowTarget(deltaTime);
		return;
	}

	FVector direction = GetActorLocation() - closestObstacle->GetActorLocation();

	direction = (target->GetActorLocation() - GetActorLocation()).GetSafeNormal() + (direction.GetSafeNormal()*avoidWeight);

	direction.Z = 0;
	FVector rot = FMath::Lerp(GetActorForwardVector(), (direction), deltaTime*speedRot);

	SetActorRotation(rot.Rotation());
	SetActorLocation(GetActorLocation() + GetActorForwardVector()*speed*deltaTime);
}

void ANewAI::AIOverlap(AActor * overlapActor)
{
	if (overlapActor == this || overlapActor == target) return;

	if (closestObstacle)
	{
		FVector a = closestObstacle->GetActorLocation() - GetActorLocation();
		FVector b = overlapActor->GetActorLocation() - GetActorLocation();
		if (b.Size() < a.Size()) closestObstacle = overlapActor;
	}
	else closestObstacle = overlapActor;
}



