// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyBlueprintAsyncAction.generated.h"

USTRUCT(BlueprintType)
struct FMyStruct
{
	GENERATED_BODY()
	int n;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMyDelegate, const TArray<FMyStruct>&, ParamName1, int, ParamName2);


#define SET_DELEGATE_DISPLAYNAME(FirstDelegateName, ParamName, DisplayName) \
do{ \
    UClass* MyClassType = StaticClass(); \
    FMulticastDelegateProperty* DelegateFun = (FMulticastDelegateProperty*)MyClassType->FindPropertyByName(#FirstDelegateName); \
	if (DelegateFun) \
	{ \
		FProperty* Param = DelegateFun->SignatureFunction->FindPropertyByName(#ParamName); \
		if (Param) \
		{ \
			Param->NamePrivate = TEXT(#DisplayName); \
		} \
	} \
} while(0)

UCLASS()
class DELEGATEDISPLAYNAME_API UMyBlueprintAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UMyBlueprintAsyncAction()
	{
		SET_DELEGATE_DISPLAYNAME(OnSuccess, ParamName1, 第一个参数);
		SET_DELEGATE_DISPLAYNAME(OnSuccess, ParamName2, 第二个参数);
	}

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="成功时", AdvancedDisplay="中文参数名"))
	FMyDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "失败时", AdvancedDisplay = "中文参数名"))
	FMyDelegate OnFailure;
	
	UFUNCTION(BlueprintCallable, meta=(DisplayName="测试函数", HideThen=true), Category="中文节点")
	static UMyBlueprintAsyncAction* TestFunc(UPARAM(DisplayName="入参") int InParam);

private:
	TArray<FMyStruct> arr;
};
