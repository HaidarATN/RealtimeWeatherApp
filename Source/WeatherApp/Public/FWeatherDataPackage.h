// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FWeatherDataPackage.generated.h"

USTRUCT(BlueprintType)
struct WEATHERAPP_API FWeatherDataPackage
{
public:
	GENERATED_BODY()

	FWeatherDataPackage();
	~FWeatherDataPackage();

	UPROPERTY(BlueprintReadOnly)
		FString MainWeather;
		
	UPROPERTY(BlueprintReadOnly)
		FString MainWeatherDetails;
		
	UPROPERTY(BlueprintReadOnly)
		float CurrentTime;
		
	UPROPERTY(BlueprintReadOnly)
		float CurrentTemp;
		
	UPROPERTY(BlueprintReadOnly)
		float WindSpeed;
		
	UPROPERTY(BlueprintReadOnly)
		FString CountryOrigin;

	UPROPERTY(BlueprintReadOnly)
		int ReturnCode;
};
