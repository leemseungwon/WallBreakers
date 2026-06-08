// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WallBreakerCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWallBreakerCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WallBreaker();
WALLBREAKER_API UClass* Z_Construct_UClass_AWallBreakerCharacter();
WALLBREAKER_API UClass* Z_Construct_UClass_AWallBreakerCharacter_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AWallBreakerCharacter ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AWallBreakerCharacter;
UClass* AWallBreakerCharacter::GetPrivateStaticClass()
{
	using TClass = AWallBreakerCharacter;
	if (!Z_Registration_Info_UClass_AWallBreakerCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WallBreakerCharacter"),
			Z_Registration_Info_UClass_AWallBreakerCharacter.InnerSingleton,
			StaticRegisterNativesAWallBreakerCharacter,
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
	return Z_Registration_Info_UClass_AWallBreakerCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_AWallBreakerCharacter_NoRegister()
{
	return AWallBreakerCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AWallBreakerCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A controllable top-down perspective character\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "WallBreakerCharacter.h" },
		{ "ModuleRelativePath", "WallBreakerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A controllable top-down perspective character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TopDownCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Top down camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WallBreakerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Top down camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera above the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WallBreakerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera above the character" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AWallBreakerCharacter constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TopDownCameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AWallBreakerCharacter constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWallBreakerCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AWallBreakerCharacter_Statics

// ********** Begin Class AWallBreakerCharacter Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWallBreakerCharacter_Statics::NewProp_TopDownCameraComponent = { "TopDownCameraComponent", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWallBreakerCharacter, TopDownCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopDownCameraComponent_MetaData), NewProp_TopDownCameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWallBreakerCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWallBreakerCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWallBreakerCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallBreakerCharacter_Statics::NewProp_TopDownCameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallBreakerCharacter_Statics::NewProp_CameraBoom,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWallBreakerCharacter_Statics::PropPointers) < 2048);
// ********** End Class AWallBreakerCharacter Property Definitions *********************************
UObject* (*const Z_Construct_UClass_AWallBreakerCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_WallBreaker,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWallBreakerCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWallBreakerCharacter_Statics::ClassParams = {
	&AWallBreakerCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AWallBreakerCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AWallBreakerCharacter_Statics::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWallBreakerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AWallBreakerCharacter_Statics::Class_MetaDataParams)
};
void AWallBreakerCharacter::StaticRegisterNativesAWallBreakerCharacter()
{
}
UClass* Z_Construct_UClass_AWallBreakerCharacter()
{
	if (!Z_Registration_Info_UClass_AWallBreakerCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWallBreakerCharacter.OuterSingleton, Z_Construct_UClass_AWallBreakerCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWallBreakerCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AWallBreakerCharacter);
AWallBreakerCharacter::~AWallBreakerCharacter() {}
// ********** End Class AWallBreakerCharacter ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h__Script_WallBreaker_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWallBreakerCharacter, AWallBreakerCharacter::StaticClass, TEXT("AWallBreakerCharacter"), &Z_Registration_Info_UClass_AWallBreakerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWallBreakerCharacter), 1488701416U) },
	};
}; // Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h__Script_WallBreaker_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h__Script_WallBreaker_3791469851{
	TEXT("/Script/WallBreaker"),
	Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h__Script_WallBreaker_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h__Script_WallBreaker_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
