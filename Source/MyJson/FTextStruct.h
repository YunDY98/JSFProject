#pragma once

#include "CoreMinimal.h"

#include "FTextStruct.generated.h"

USTRUCT(BlueprintType)
struct FTextStruct
{
	GENERATED_BODY()
public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JsonText")
		TArray<FString> Text;



	

};