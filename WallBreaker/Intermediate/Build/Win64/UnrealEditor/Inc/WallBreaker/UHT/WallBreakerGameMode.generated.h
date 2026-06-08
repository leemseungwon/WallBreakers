// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WallBreakerGameMode.h"

#ifdef WALLBREAKER_WallBreakerGameMode_generated_h
#error "WallBreakerGameMode.generated.h already included, missing '#pragma once' in WallBreakerGameMode.h"
#endif
#define WALLBREAKER_WallBreakerGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AWallBreakerGameMode *****************************************************
struct Z_Construct_UClass_AWallBreakerGameMode_Statics;
WALLBREAKER_API UClass* Z_Construct_UClass_AWallBreakerGameMode_NoRegister();

#define FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWallBreakerGameMode(); \
	friend struct ::Z_Construct_UClass_AWallBreakerGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WALLBREAKER_API UClass* ::Z_Construct_UClass_AWallBreakerGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AWallBreakerGameMode, AGameModeBase, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/WallBreaker"), Z_Construct_UClass_AWallBreakerGameMode_NoRegister) \
	DECLARE_SERIALIZER(AWallBreakerGameMode)


#define FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AWallBreakerGameMode(AWallBreakerGameMode&&) = delete; \
	AWallBreakerGameMode(const AWallBreakerGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWallBreakerGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWallBreakerGameMode); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AWallBreakerGameMode) \
	NO_API virtual ~AWallBreakerGameMode();


#define FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h_14_PROLOG
#define FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h_17_INCLASS_NO_PURE_DECLS \
	FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AWallBreakerGameMode;

// ********** End Class AWallBreakerGameMode *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WallBreaker_Source_WallBreaker_WallBreakerGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
