// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJsonActor.h"
#include "Misc/FileHelper.h"

// Sets default values
AMyJsonActor::AMyJsonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FString FileStr;
    FString FilePath = TEXT("C:/UE_/MyJson/Content/Json/ButtonJson.json");
    FFileHelper::LoadFileToString(FileStr, *FilePath);


    TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(FileStr);
    TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

    if (FJsonSerializer::Deserialize(jsonReader, jsonObj) && jsonObj.IsValid())
    {
        
        jsonObj->TryGetStringField(TEXT("ButtonName"), CharName);

        FString Value = jsonObj->GetStringField(TEXT("ButtonName"));

        aa = Value;
      
  /*
        TArray<FItemData> ItemDatas;
        const TArray<TSharedPtr<FJsonValue>>* jsonItems;
        if (JsonObject->TryGetArrayField(TEXT("items"), jsonItems))
        {
            for (int i = 0; i < jsonItems.Num(); i++)
            {
                TSharedPtr<FJsonObject> jsonItem = jsonItems[i]->AsObject();
                FItemData AddData;
                jsonItem->TryGetNumberField(TEXT("Name"), AddData.ItemID);
              
                ItemDatas.Add(AddData);
            }*/
        }
  


}

// Called when the game starts or when spawned
void AMyJsonActor::BeginPlay()
{
	Super::BeginPlay();
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,CharName);
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, aa);
  
  
    
}

// Called every frame
void AMyJsonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

