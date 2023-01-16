
// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJsonComponent.h"

// Sets default values for this component's properties
UMyJsonComponent::UMyJsonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyJsonComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyJsonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



FString UMyJsonComponent::fPrintFPlayerStruct(FPlayerStruct p)
{
	FString resp = "";
	
	resp += "name: " + p.name + "\r\n";
	resp += "HP: " + FString::FromInt(p.HP) + "\r\n";
	resp += "MP: " + FString::FromInt(p.MP) + "\r\n";
	resp += "AP: " + FString::SanitizeFloat(p.AP) + "\r\n"; // Ap가 10.20이 아니라 10.00으로 출력됨 
	
	resp += "inventory: \r\n";
	//resp += "inventory: ";

	for (int32 i = 0; i < p.aInventory.Num(); i++)
	{
		resp += "id: " + FString::FromInt(p.aInventory[i].id) + "\r\n";
		resp += "name: " + p.aInventory[i].name + "\r\n";
		resp += "count: " + FString::FromInt(p.aInventory[i].count) + "\r\n";
	}

	return resp;
}

void UMyJsonComponent::MyLoadJson()
{
	bool bok = true;

	FString fileName = "common.json";

	FString fullPathContent = FPaths::ProjectContentDir() + fileName;

	FString jsonStr;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*fullPathContent))
	{
		bok = false;
	}
	/*	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());*/
	if (bok)
	{
		
		
		
		FString JsonString;
		FFileHelper::LoadFileToString(JsonString, *(FPaths::ProjectContentDir() + TEXT("common.json")));

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

	

		if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
		{
			TArray<TSharedPtr<FJsonValue>> EmployeesArr = JsonObject->GetArrayField(TEXT("Common"));
			TSharedPtr<FJsonValue>  EmployeesValue;
		
			TSharedPtr<FJsonObject> EmployeesValueObject;
		//
		//	for (int i = 0; i < EmployeesArr.Num(); i++)
		//	{
		//		EmployeesValue = EmployeesArr[i];
		//		EmployeesValueObject = EmployeesValue->AsObject();
		//	
		//		EmployeesValueObject->TryGetStringArrayField("text", Text);
		//		
		//		//GEngine->AddOnScreenDebugMessage(-1, 120, FColor::Red, TEXT("i ::"+i));
		//		UE_LOG(LogTemp, Warning, TEXT("nddd :: %d"),i);
		//		
		//	}



		//	for (int32 i = 0; i < Text.Num(); ++i)
		//{
		//	//CommonStruct.aText0.Add(Text[i]);
		//	CommonStruct.test.Add(Text[i]);
		//}


		
			TSharedPtr<FJsonValue>  Ev;
			TSharedPtr<FJsonObject> Evo;
			Ev = EmployeesArr[1];
			Evo = Ev->AsObject();
			Evo->TryGetStringArrayField("text", Test);

			
			for (int32 i = 0; i < Test.Num(); ++i)
			{
				//CommonStruct.aText0.Add(Text[i]);
				CommonStruct.test.Add(Test[i]);
			}

		
		}
		
		

		
		

	}


	
}

TArray<FString> UMyJsonComponent::MyPrintFPlayerStruct(FCommonStruct p)
{

	//for (int32 i = 0; i < Text.Num(); ++i)
	//{
	//	//p.aText0.Add(Text[i]);
	//}
	//p.aText0.Add(Text[0]);

	p.test.Add(Test[0]);


	
	

	return p.test;
	
	//return p.aText0;

}





void UMyJsonComponent::fLoadJson()
{
	bool bok = true;

	FString fileName = "jsonData.json";

	FString fullPathContent = FPaths::ProjectContentDir() + fileName;

	FString jsonStr;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*fullPathContent))
	{
		bok = false;
	}
	/*	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());*/
	if (bok)
	{
		FFileHelper::LoadFileToString(jsonStr, *fullPathContent);

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);

		//TSharedRef<FJsonObject> JsonObject = MakeShared(new FJsonObject);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
		//ref로 가져오면 왜 안되지??

	

		FJsonSerializer::Deserialize(JsonReader, JsonObject);

		TSharedPtr<FJsonObject> player = JsonObject->GetObjectField("player");
		
		this->playerStruct.name = player->GetStringField("name");
		this->playerStruct.HP = player->GetIntegerField("HP");
		this->playerStruct.MP = player->GetIntegerField("MP");
		this->playerStruct.AP = player->GetIntegerField("AP");

		TArray<TSharedPtr<FJsonValue>> aInventory;
		aInventory = player->GetArrayField("inventory");

		FPlayerInventoryStruct item;
		for (int32 i = 0; i < aInventory.Num(); i++)
		{
			item.id = aInventory[i]->AsObject()->GetIntegerField("id");
			item.count = aInventory[i]->AsObject()->GetIntegerField("count");
			item.name = aInventory[i]->AsObject()->GetStringField("name");
			JsonData.Add(item.name);
			//JsonData[i] = item.name;
;			this->playerStruct.aInventory.Add(item);
		}
	}


}

