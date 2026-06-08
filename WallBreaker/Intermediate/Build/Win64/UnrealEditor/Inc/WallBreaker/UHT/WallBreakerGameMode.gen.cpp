// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WallBreakerGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWallBreakerGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_WallBreaker();
WALLBREAKER_API UClass* Z_Construct_UClass_AWallBreakerGameMode();
WALLBREAKER_API UClass* Z_Construct_UClass_AWallBreakerGameMode_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AWallBreakerGameMode *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AWallBreakerGameMode;
UClass* AWallBreakerGameMode::GetPrivateStaticClass()
{
	using TClass = AWallBreakerGameMode;
	if (!Z_Registration_Info_UClass_AWallBreakerGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WallBreakerGameMode"),
			Z_Registration_Info_UClass_AWallBreakerGameMode.InnerSingleton,
			StaticRegisterNativesAWallBreakerGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AWallBreakerGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AWallBreakerGameMode_NoRegister()
{
	return AWallBreakerGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AWallBreakerGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple Game Mode for a top-down perspective game\n *  Sets the default gameplay framework classes\n *  Check the Blueprint derived class for the set values\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "WallBreakerGameMode.h" },
		{ "ModuleRelativePath", "WallBreakerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple Game Mode for a top-down perspective game\nSets the default gameplay framework classes\nCheck the Blueprint derived class for the set values" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AWallBreakerGameMode constinit property declarations *********************
// ********** End Class AWallBreakerGameMode constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWallBreakerGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AWallBreakerGameMode_Statics
UObject* (*const Z_Construct_UClass_AWallBreakerGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_WallBreaker,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWallBreakerGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWallBreakerGameMode_Statics::ClassParams = {
	&AWallBreakerGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWallBreakerGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AWallBreakerGameMode_Statics::Class_MetaDataParams)
};
void AWallBreakerGameMode::StaticRegisterNativesAWallBreakerGameMode()
{
}
UClass* Z_Construct_UClass_AWallBreakerGameMode()
{
	if (!Z_Registration_Info_UClass_AWallBreakerGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWallBreakerGameMode.OuterSingleton, Z_Construct_UClass_AWallBreakerGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWallBreakerGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AWallBreakerGameMode);
AWallBreakerGameMode::~AWallBreakerGameMode() {}
// ********** End Class AWallBreakerGameMode *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h__Script_WallBreaker_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWallBreakerGameMode, AWallBreakerGameMode::StaticClass, TEXT("AWallBreakerGameMode"), &Z_Registration_Info_UClass_AWallBreakerGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWallBreakerGameMode), 3823696500U) },
	};
}; // Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h__Script_WallBreaker_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h__Script_WallBreaker_3876611597{
	TEXT("/Script/WallBreaker"),
	Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h__Script_WallBreaker_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h__Script_WallBreaker_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
