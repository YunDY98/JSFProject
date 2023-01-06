// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JsonStruct.h"
#include "ST_Json.generated.h"

UCLASS()
class MYJSON_API AST_Json : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AST_Json();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		FCustomStruct cs;


};
