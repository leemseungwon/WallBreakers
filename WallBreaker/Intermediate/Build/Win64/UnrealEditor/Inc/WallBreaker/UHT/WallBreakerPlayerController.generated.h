// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WallBreakerPlayerController.h"

#ifdef WALLBREAKER_WallBreakerPlayerController_generated_h
#error "WallBreakerPlayerController.generated.h already included, missing '#pragma once' in WallBreakerPlayerController.h"
#endif
#define WALLBREAKER_WallBreakerPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AWallBreakerPlayerController *********************************************
struct Z_Construct_UClass_AWallBreakerPlayerController_Statics;
WALLBREAKER_API UClass* Z_Construct_UClass_AWallBreakerPlayerController_NoRegister();

#define FID_WallBreaker_Source_WallBreaker_WallBreakerPlayerController_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWallBreakerPlayerController(); \
	friend struct ::Z_Construct_UClass_AWallBreakerPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WALLBREAKER_API UClass* ::Z_Construct_UClass_AWallBreakerPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AWallBreakerPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/WallBreaker"), Z_Construct_UClass_AWallBreakerPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AWallBreakerPlayerController)


#define FID_WallBreaker_Source_WallBreaker_WallBreakerPlayerController_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AWallBreakerPlayerController(AWallBreakerPlayerController&&) = delete; \
	AWallBreakerPlayerController(const AWallBreakerPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWallBreakerPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWallBreakerPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AWallBreakerPlayerController) \
	NO_API virtual ~AWallBreakerPlayerController();


#define FID_WallBreaker_Source_WallBreaker_WallBreakerPlayerController_h_21_PROLOG
#define FID_WallBreaker_Source_WallBreaker_WallBreakerPlayerController_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WallBreaker_Source_WallBreaker_WallBreakerPlayerController_h_24_INCLASS_NO_PURE_DECLS \
	FID_WallBreaker_Source_WallBreaker_WallBreakerPlayerController_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AWallBreakerPlayerController;

// ********** End Class AWallBreakerPlayerController ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WallBreaker_Source_WallBreaker_WallBreakerPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
