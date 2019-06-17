// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

void AMyPlayerController::BeginPlay()
{
	myCanvas = CreateWidget<UMyUserWidget>(this, prefabUI);
	if (myCanvas) myCanvas->AddToViewport();
}

void AMyPlayerController::TakeDamageUI()
{
	damageCanvas = CreateWidget<UMyUserWidget>(this, prefabDamageUI);
	if (damageCanvas) damageCanvas->AddToViewport();
}

void AMyPlayerController::TakeDamageUIRemove()
{
	if (damageCanvas) damageCanvas->RemoveFromViewport();
}
