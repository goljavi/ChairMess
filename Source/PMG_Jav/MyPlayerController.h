// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyUserWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PMG_JAV_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UMyUserWidget> prefabUI;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UMyUserWidget> prefabDamageUI;
	UPROPERTY(EditAnywhere)
		float speed;

	UMyUserWidget* myCanvas;
	UMyUserWidget* damageCanvas;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void TakeDamageUI();

	UFUNCTION(BlueprintCallable)
		void TakeDamageUIRemove();
};
