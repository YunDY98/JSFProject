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
//atomic�� �׻� �ϳ��� ������ ����ȭ??
//blueprinttype�� �̱���ü�� �������Ʈ���� ��밡��
USTRUCT(Atomic,BlueprintType)
struct FCustomStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AActor* actor;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Name;


};