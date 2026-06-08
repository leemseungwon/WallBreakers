// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Variant_TwinStick/UI/TwinStickUI.h"

#ifdef WALLBREAKER_TwinStickUI_generated_h
#error "TwinStickUI.generated.h already included, missing '#pragma once' in TwinStickUI.h"
#endif
#define WALLBREAKER_TwinStickUI_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UTwinStickUI *************************************************************
#define FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_16_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UTwinStickUI_Statics;
WALLBREAKER_API UClass* Z_Construct_UClass_UTwinStickUI_NoRegister();

#define FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTwinStickUI(); \
	friend struct ::Z_Construct_UClass_UTwinStickUI_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WALLBREAKER_API UClass* ::Z_Construct_UClass_UTwinStickUI_NoRegister(); \
public: \
	DECLARE_CLASS2(UTwinStickUI, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/WallBreaker"), Z_Construct_UClass_UTwinStickUI_NoRegister) \
	DECLARE_SERIALIZER(UTwinStickUI)


#define FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTwinStickUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTwinStickUI(UTwinStickUI&&) = delete; \
	UTwinStickUI(const UTwinStickUI&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTwinStickUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTwinStickUI); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTwinStickUI) \
	NO_API virtual ~UTwinStickUI();


#define FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_13_PROLOG
#define FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_16_CALLBACK_WRAPPERS \
	FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_16_INCLASS_NO_PURE_DECLS \
	FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTwinStickUI;

// ********** End Class UTwinStickUI ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WallBreaker_Source_WallBreaker_Variant_TwinStick_UI_TwinStickUI_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
