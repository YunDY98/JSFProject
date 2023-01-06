// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "MyJsonNameWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYJSON_API UMyJsonNameWidget : public UUserWidget
{
	GENERATED_BODY()
	


// Widget.h
public:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* ButtonText;

	UPROPERTY(BlueprintReadOnly)
		FString ButtonName = "test";


	

};
