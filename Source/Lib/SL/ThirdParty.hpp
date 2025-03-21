/**
 * @File ThirdParty.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2025/03/21
 * @Brief This file is part of SunLight.
 */

#pragma once

#include <fmt/format.h>
#include <fmt/color.h>
#include <magic_enum/magic_enum_all.hpp>
#include <stringzilla/stringzilla.hpp>

namespace sl {
// ==================
// magic enum 
// ==================

namespace me = magic_enum;
namespace mec = magic_enum::containers;
#define BEE_USE_MAGIC_ENUM_BIT_OPERATOR using namespace magic_enum::bitwise_operators

using me::iostream_operators::operator<<;
using me::iostream_operators::operator>>;

template<typename E>
    requires std::is_enum_v<E>
constexpr std::string_view ToString(E e)
{
    return me::enum_name(e);
}

template<typename E>
    requires std::is_enum_v<E>
constexpr bool InSet(E mask, E e)
{
    BEE_USE_MAGIC_ENUM_BIT_OPERATOR;
    return (mask & e) == e;
}

// ==================
// stringzilla
// ==================

namespace sz = ashvardanian::stringzilla;

using String     = sz::string;
using StringView = sz::string_view;
} // namespace sl

template<> struct fmt::formatter<sl::String>
{
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

    template<typename Context> constexpr auto format(const sl::String& bs, Context& ctx) const { return format_to(ctx.out(), "{}", bs.data()); }
};

template<> struct fmt::formatter<sl::StringView>
{
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

    template<typename Context> constexpr auto format(const sl::StringView& bsv, Context& ctx) const
    {
        return format_to(ctx.out(), "{}", bsv.data());
    }
};