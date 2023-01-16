// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::ParseJson_Switching(TArray<FString>& Text)
{
	

	FString JsonString;
	FFileHelper::LoadFileToString(JsonString, *(FPaths::ProjectContentDir() + TEXT("common.json")));

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		TArray<TSharedPtr<FJsonValue>> EmployeesArr = JsonObject->GetArrayField(TEXT("Common"));

		for (int32 i = 0; i < EmployeesArr.Num(); i++)
		{
			TSharedPtr<FJsonValue>  EmployeesValue = EmployeesArr[i];
			TSharedPtr<FJsonObject> EmployeesValueObject = EmployeesValue->AsObject();

			EmployeesValueObject->TryGetStringArrayField("text",Text);
			
		}
	}
}


