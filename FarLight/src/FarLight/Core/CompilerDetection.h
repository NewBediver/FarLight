#pragma once

#if (defined( __WIN32__ ) || defined( _WIN32 )) && defined(__ANDROID__) // We are using NVTegra
#   define FL_COMPILER_GNUC
#   define FL_COMP_VER 470
#elif defined(__GCCE__)
#   define FL_COMPILER_GCCE
#   define FL_COMP_VER _MSC_VER
#   include <staticlibinit_gcce.h> // This is a GCCE toolchain workaround needed when compiling with GCCE 
#elif defined(__WINSCW__)
#   define FL_COMPILER_WINSCW
#   define FL_COMP_VER _MSC_VER
#elif defined(_MSC_VER)
#   define FL_COMPILER_MSVC
#   define FL_COMP_VER _MSC_VER
#elif defined(__clang__)
#   define FL_COMPILER_CLANG
#   define FL_COMP_VER (((__clang_major__) * 100) + (__clang_minor__*10) + __clang_patchlevel__)
#elif defined(__GNUC__)
#   define FL_COMPILER_GNUC
#   define FL_COMP_VER (((__GNUC__) * 100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
#elif defined(__BORLANDC__)
#   define FL_COMPILER_BORL
#   define FL_COMP_VER __BCPLUSPLUS__
#   define __FUNCTION__ __FUNC__
#else
#   error "Unknown compiler!"
#endif
