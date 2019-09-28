// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "NewAI.generated.h"

UENUM(BlueprintType)
enum class EAIBehaviour : uint8
{
	FollowTarget UMETA(DisplayName = "Follow Target"),
	ObstacleAvoidance UMETA(DisplayName = "Obstacle Avoidance"),
};


UCLASS()
class PMG_JAV_API ANewAI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewAI();

	UPROPERTY(VisibleAnywhere)
		AActor* target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EAIBehaviour currentBehaviour;

	UPROPERTY(EditAnywhere)
		float speed;

	UPROPERTY(EditAnywhere)
		float speedRot;

	UPROPERTY(EditAnywhere)
		float avoidWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* closestObstacle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ObstacleAvoidance(float deltaTime);
	void FollowTarget(float deltaTime);
	UFUNCTION(BlueprintCallable) void AIOverlap(AActor* overlapActor);

	
	
};
