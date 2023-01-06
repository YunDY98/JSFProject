// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonStruct.generated.h"

/**
 * 
 */
class MYJSON_API JsonStruct
{
public:
	JsonStruct();
	~JsonStruct();
};
//atomic은 항상 하나의 단위로 직렬화??
//blueprinttype은 이구조체가 블루프린트에서 사용가능
USTRUCT(Atomic,BlueprintType)
struct CustomStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere,)
	AActor* actor;
	
	FString Name;


};