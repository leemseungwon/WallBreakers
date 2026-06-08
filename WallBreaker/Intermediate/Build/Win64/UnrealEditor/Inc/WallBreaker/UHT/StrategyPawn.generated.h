// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Variant_Strategy/StrategyPawn.h"

#ifdef WALLBREAKER_StrategyPawn_generated_h
#error "StrategyPawn.generated.h already included, missing '#pragma once' in StrategyPawn.h"
#endif
#define WALLBREAKER_StrategyPawn_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AStrategyPawn ************************************************************
struct Z_Construct_UClass_AStrategyPawn_Statics;
WALLBREAKER_API UClass* Z_Construct_UClass_AStrategyPawn_NoRegister();

#define FID_WallBreaker_Source_WallBreaker_Variant_Strategy_StrategyPawn_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAStrategyPawn(); \
	friend struct ::Z_Construct_UClass_AStrategyPawn_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WALLBREAKER_API UClass* ::Z_Construct_UClass_AStrategyPawn_NoRegister(); \
public: \
	DECLARE_CLASS2(AStrategyPawn, APawn, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/WallBreaker"), Z_Construct_UClass_AStrategyPawn_NoRegister) \
	DECLARE_SERIALIZER(AStrategyPawn)


#define FID_WallBreaker_Source_WallBreaker_Variant_Strategy_StrategyPawn_h_19_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AStrategyPawn(AStrategyPawn&&) = delete; \
	AStrategyPawn(const AStrategyPawn&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AStrategyPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AStrategyPawn); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AStrategyPawn) \
	NO_API virtual ~AStrategyPawn();


#define FID_WallBreaker_Source_WallBreaker_Variant_Strategy_StrategyPawn_h_16_PROLOG
#define FID_WallBreaker_Source_WallBreaker_Variant_Strategy_StrategyPawn_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WallBreaker_Source_WallBreaker_Variant_Strategy_StrategyPawn_h_19_INCLASS_NO_PURE_DECLS \
	FID_WallBreaker_Source_WallBreaker_Variant_Strategy_StrategyPawn_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AStrategyPawn;

// ********** End Class AStrategyPawn **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WallBreaker_Source_WallBreaker_Variant_Strategy_StrategyPawn_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
