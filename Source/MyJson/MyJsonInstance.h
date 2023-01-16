// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyJsonInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYJSON_API UMyJsonInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnyWhere,BlueprintReadWrite)
	FString ButtonGMI;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int ButtonCsvIdx = -1;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int ButtonJsonIdx = -1;

};
