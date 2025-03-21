/**
 * @File Defines.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2025/03/18
 * @Brief This file is part of SunLight.
 */

#pragma once

// -------------------------
//关于平台、编译器、语言的宏定义

#if defined(_MSC_VER)
#  define SL_API_EXPORT __declspec(dllexport)
#  define SL_API_IMPORT __declspec(dllimport)
#elif defined(__clang__) || defined(__GNUC__)
#  define SL_API_EXPORT __attribute__((visibility("default")))
#  define SL_API_IMPORT __attribute__((visibility("default")))
#else
#  define SL_API_EXPORT
#  define SL_API_IMPORT
#endif

#ifdef SL_DLL
#  define SL_API SL_API_EXPORT
#else  // SL_DLL
#  define SL_API SL_API_IMPORT
#endif // SL_DLL

#include <cstdint>
#include <cstddef>

namespace sl {
// -------------------------
// 内置类型、常量别名

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8   = uint8_t;
using u16  = uint16_t;
using u32  = uint32_t;
using u64  = uint64_t;
using uint = unsigned int;

using f32 = float;
using f64 = double;

using Size = std::size_t;

static constexpr i8 kI8Min   = INT8_MIN;
static constexpr i16 kI16Min = INT16_MIN;
static constexpr i32 kI32Min = INT32_MIN;
static constexpr i64 kI64Min = INT64_MIN;

static constexpr i8 kI8Max   = INT8_MAX;
static constexpr i16 kI16Max = INT16_MAX;
static constexpr i32 kI32Max = INT32_MAX;
static constexpr i64 kI64Max = INT64_MAX;

static constexpr u8 kU8Max   = UINT8_MAX;
static constexpr u16 kU16Max = UINT16_MAX;
static constexpr u32 kU32Max = UINT32_MAX;
static constexpr u64 kU64Max = UINT64_MAX;

} // namespace sl