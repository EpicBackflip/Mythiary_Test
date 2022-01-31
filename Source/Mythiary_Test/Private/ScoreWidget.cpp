// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"

#include "CoinSpawner.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Mythiary_Test/Mythiary_TestCharacter.h"

void UScoreWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	UpdateTexts();
}

void UScoreWidget::UpdateTexts()
{
	AMythiary_TestCharacter* Character = Cast<AMythiary_TestCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	ACoinSpawner* CoinSpawner = Cast<ACoinSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(),ACoinSpawner::StaticClass()));
	CoinsPickedUp->SetText(FText::AsNumber(Character->CoinsPickedUpInt));
	CoinsLeft->SetText(FText::AsNumber(CoinSpawner->Actors.Num()));
	Distance->SetText(FText::AsNumber(CoinSpawner->NearestDistance));
} 

