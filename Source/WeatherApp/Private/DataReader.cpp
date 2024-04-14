// Fill out your copyright notice in the Description page of Project Settings.


#include "DataReader.h"
#include "JsonUtilities.h"
#include "Json.h"

// Sets default values
ADataReader::ADataReader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataReader::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADataReader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADataReader::GetWeatherData(FString WeatherJsonData)
{
	ReadData(WeatherJsonData);
}

FWeatherDataPackage ADataReader::ReadData(FString WeatherData)
{
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(WeatherData);
	TSharedPtr<FJsonObject> WeatherDataJSONObject = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(JsonReader, WeatherDataJSONObject) && WeatherDataJSONObject.IsValid()) {
		//TSharedPtr<FJsonObject> CurrentWeather = TranslatedWeatherData->GetObjectField("weather");

		if (WeatherDataJSONObject->GetIntegerField("cod") == 404) {
			GLog->Log(WeatherDataJSONObject->GetStringField("message"));
			MainWeather = WeatherDataJSONObject->GetStringField("message");
			ReturnCode = WeatherDataJSONObject->GetIntegerField("cod");
		}

		else {
			GLog->Log("Current Weather : " + WeatherDataJSONObject->GetArrayField("weather")[0]->AsObject()->GetStringField("main"));

			MainWeather = WeatherDataJSONObject->GetArrayField("weather")[0]->AsObject()->GetStringField("main");
			MainWeatherDetails = WeatherDataJSONObject->GetArrayField("weather")[0]->AsObject()->GetStringField("description");
			CountryOrigin = WeatherDataJSONObject->GetObjectField("sys")->GetStringField("country");
			CurrentTime = WeatherDataJSONObject->GetIntegerField("timezone");
			CurrentTemp = WeatherDataJSONObject->GetObjectField("main")->GetStringField("temp");
			WindSpeed = WeatherDataJSONObject->GetObjectField("wind")->GetStringField("speed");
			ReturnCode = WeatherDataJSONObject->GetIntegerField("cod");
		}
		
	}

	FWeatherDataPackage DataPackage;
	DataPackage.MainWeather = MainWeather;
	DataPackage.MainWeatherDetails = MainWeatherDetails;
	DataPackage.CountryOrigin = CountryOrigin;
	DataPackage.CurrentTime = CurrentTime;
	DataPackage.CurrentTemp = FCString::Atof(*CurrentTemp);
	DataPackage.WindSpeed = FCString::Atof(*WindSpeed);
	DataPackage.ReturnCode = ReturnCode;

	return DataPackage;
}

