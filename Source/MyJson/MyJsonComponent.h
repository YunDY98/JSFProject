// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "FPlayerStruct.h"
#include "FPlayerInventoryStruct.h"
#include "FTextStruct.h"
#include "FCommonStruct.h"
#include "MyBlueprintFunctionLibrary.h"
#include "MyJsonComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYJSON_API UMyJsonComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyJsonComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	FPlayerStruct playerStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FCommonStruct CommonStruct;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		TArray<FString> Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		TArray<FString> Test;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	//	FCommonStruct commonStruct;


	UFUNCTION(BlueprintCallable,Category = "AA")
	void fLoadJson();

	UFUNCTION(BlueprintCallable, Category = "AA")
	FString fPrintFPlayerStruct(FPlayerStruct p);

	UFUNCTION(BlueprintCallable, Category = "AA")
		void MyLoadJson();

	UFUNCTION(BlueprintCallable, Category = "AA")
		TArray<FString> MyPrintFPlayerStruct(FCommonStruct p);




	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		TArray<FString> JsonData;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		TArray<FString> CommonJsonData;


};
