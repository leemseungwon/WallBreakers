// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WallBreakerCharacter.h"

#ifdef WALLBREAKER_WallBreakerCharacter_generated_h
#error "WallBreakerCharacter.generated.h already included, missing '#pragma once' in WallBreakerCharacter.h"
#endif
#define WALLBREAKER_WallBreakerCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AWallBreakerCharacter ****************************************************
struct Z_Construct_UClass_AWallBreakerCharacter_Statics;
WALLBREAKER_API UClass* Z_Construct_UClass_AWallBreakerCharacter_NoRegister();

#define FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWallBreakerCharacter(); \
	friend struct ::Z_Construct_UClass_AWallBreakerCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WALLBREAKER_API UClass* ::Z_Construct_UClass_AWallBreakerCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AWallBreakerCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/WallBreaker"), Z_Construct_UClass_AWallBreakerCharacter_NoRegister) \
	DECLARE_SERIALIZER(AWallBreakerCharacter)


#define FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AWallBreakerCharacter(AWallBreakerCharacter&&) = delete; \
	AWallBreakerCharacter(const AWallBreakerCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWallBreakerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWallBreakerCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AWallBreakerCharacter) \
	NO_API virtual ~AWallBreakerCharacter();


#define FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h_15_PROLOG
#define FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h_18_INCLASS_NO_PURE_DECLS \
	FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AWallBreakerCharacter;

// ********** End Class AWallBreakerCharacter ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WallBreaker_Source_WallBreaker_WallBreakerCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
