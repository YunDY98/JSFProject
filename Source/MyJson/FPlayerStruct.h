#pragma once


#include "CoreMinimal.h"
#include "FPlayerInventoryStruct.h"

#include "FPlayerStruct.generated.h"

USTRUCT(BlueprintType)
struct FPlayerStruct
{
	GENERATED_BODY()

public:



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FString name = ""; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 HP = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 MP = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		float AP = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		TArray<FPlayerInventoryStruct> aInventory;

};