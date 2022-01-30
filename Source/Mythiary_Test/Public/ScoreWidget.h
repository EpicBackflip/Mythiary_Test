// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

UCLASS()
class MYTHIARY_TEST_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
		UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* CoinsPickedUp;
		virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:
	void UpdateScore();
};
