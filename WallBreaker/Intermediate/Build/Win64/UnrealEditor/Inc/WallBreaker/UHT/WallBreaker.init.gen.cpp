// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWallBreaker_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	WALLBREAKER_API UFunction* Z_Construct_UDelegateFunction_WallBreaker_OnUnitMoveCompletedDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_WallBreaker;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_WallBreaker()
	{
		if (!Z_Registration_Info_UPackage__Script_WallBreaker.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_WallBreaker_OnUnitMoveCompletedDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/WallBreaker",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x0A57D14B,
			0x084AF7B8,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_WallBreaker.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_WallBreaker.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_WallBreaker(Z_Construct_UPackage__Script_WallBreaker, TEXT("/Script/WallBreaker"), Z_Registration_Info_UPackage__Script_WallBreaker, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0A57D14B, 0x084AF7B8));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
