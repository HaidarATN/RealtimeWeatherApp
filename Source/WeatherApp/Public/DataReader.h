// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FWeatherDataPackage.h"
#include "DataReader.generated.h"

//USTRUCT(BlueprintType)
//struct FWeatherDataPackage {
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY(BlueprintReadOnly)
//		FString MainWeather;
//
//	UPROPERTY(BlueprintReadOnly)
//		FString MainWeatherDetails;
//
//	UPROPERTY(BlueprintReadOnly)
//		float CurrentTime;
//
//	UPROPERTY(BlueprintReadOnly)
//		FString CurrentTemp;
//
//	UPROPERTY(BlueprintReadOnly)
//		FString WindSpeed;
//
//	UPROPERTY(BlueprintReadOnly)
//		FString CountryOrigin;
//};

UCLASS()
class WEATHERAPP_API ADataReader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADataReader();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category="Weather Data")
		FString MainWeather;

	UPROPERTY(BlueprintReadOnly, Category = "Weather Data")
		FString MainWeatherDetails;

	UPROPERTY(BlueprintReadOnly, Category = "Weather Data")
		float CurrentTime;

	UPROPERTY(BlueprintReadOnly, Category = "Weather Data", meta=(ToolTip="Temp in Kelvin"))
		FString CurrentTemp;

	UPROPERTY(BlueprintReadOnly, Category = "Weather Data", meta = (ToolTip = "meter/sec"))
		FString WindSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Weather Data")
		FString CountryOrigin;

	UPROPERTY(BlueprintReadOnly, Category = "Weather Data")
		int ReturnCode;

	UFUNCTION(BlueprintCallable)
		void GetWeatherData(FString WeatherJsonData);

	UFUNCTION(BlueprintCallable)
		FWeatherDataPackage ReadData(FString WeatherData);
};
