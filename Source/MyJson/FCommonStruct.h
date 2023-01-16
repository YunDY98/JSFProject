#pragma once

#include "CoreMinimal.h"
#include "FTextStruct.h"
#include "FCommonStruct.generated.h"

USTRUCT(BlueprintType)
struct FCommonStruct
{
	GENERATED_BODY()
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		TArray<FString> aText0;//0~14 15~29 30~44
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		TArray<FString> test;


};