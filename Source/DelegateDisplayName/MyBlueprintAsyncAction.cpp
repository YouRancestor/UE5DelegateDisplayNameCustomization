// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintAsyncAction.h"

//UMyBlueprintAsyncAction::UMyBlueprintAsyncAction()
//{
//
//    SET_DELEGATE_DISPLAYNAME(OnSuccess, ParamName, 中文参数);
//
//}

UMyBlueprintAsyncAction* UMyBlueprintAsyncAction::TestFunc(int InParam)
{
	UClass* MyClassType = StaticClass();
	
	MyClassType->AddCppProperty(NULL);

	FMulticastDelegateProperty* DelegateFun = (FMulticastDelegateProperty*)MyClassType->FindPropertyByName("FirstDelegateName");
	if (DelegateFun)
	{
		FProperty* Param = DelegateFun->SignatureFunction->FindPropertyByName("ParamName");
		if (Param)
		{
			Param->NamePrivate = TEXT("DisplayName");
		}
	}

	
	
	
	
	auto p = NewObject<UMyBlueprintAsyncAction>();
    return p;
}