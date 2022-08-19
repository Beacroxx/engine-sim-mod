#ifndef PIRANHA_FUNDAMENTAL_TYPES_H
#define PIRANHA_FUNDAMENTAL_TYPES_H

#include "channel_type.h"

#include <string>

namespace piranha {

    struct FundamentalType {
        static const ChannelType FloatType;
        static const ChannelType IntType;
        static const ChannelType StringType;
        static const ChannelType BoolType;
        static const ChannelType VectorType;
    };

    struct vector {
        double x;
        double y;
        double z;
        double w;

        vector operator+(const vector &v) const {
            return { x + v.x, y + v.y, z + v.z, w + v.w };
        }

        vector operator-(const vector &v) const {
            return { x - v.x, y - v.y, z - v.z, w - v.w };
        }

        vector operator/(const vector &v) const {
            return { x / v.x, y / v.y, z / v.z, w / v.w };
        }

        vector operator*(const vector &v) const {
            return { x * v.x, y * v.y, z * v.z, w * v.w };
        }

        vector operator-() const {
            return { -x, -y, -z, -w };
        }
    };

    // Native types
    typedef double          native_float;
    typedef bool            native_bool;
    typedef std::string     native_string;
    typedef int             native_int;
    typedef vector          native_vector;

    enum class LiteralType {
        Float,
        Boolean,
        String,
        Integer,
        Undefined
    };

    template <typename T>
    bool dependantFalse() {
        // This stops clang/gcc from seeing the static_assert is always false
        return false;
    }

    template <typename NativeType>
    inline LiteralType LiteralTypeLookup() { static_assert(dependantFalse<NativeType>, "Looking up a type that does not exist"); return LiteralType::Undefined; };

    template <> inline LiteralType LiteralTypeLookup<native_float>() { return LiteralType::Float; }
    template <> inline LiteralType LiteralTypeLookup<native_bool>() { return LiteralType::Boolean; }
    template <> inline LiteralType LiteralTypeLookup<native_int>() { return LiteralType::Integer; }
    template <> inline LiteralType LiteralTypeLookup<native_string>() { return LiteralType::String; }

    template <typename NativeType>
    inline const ChannelType *NativeTypeLookup() { static_assert(dependantFalse<NativeType>, "Looking up a type that does not exist"); return nullptr; }

    template <> inline const ChannelType *NativeTypeLookup<native_float>() { return &FundamentalType::FloatType; }
    template <> inline const ChannelType *NativeTypeLookup<native_bool>() { return &FundamentalType::BoolType; }
    template <> inline const ChannelType *NativeTypeLookup<native_int>() { return &FundamentalType::IntType; }
    template <> inline const ChannelType *NativeTypeLookup<native_string>() { return &FundamentalType::StringType; }
    template <> inline const ChannelType *NativeTypeLookup<native_vector>() { return &FundamentalType::VectorType; }

} /* namespace piranha */

#endif /* PIRANHA_FUNDAMENTAL_TYPES_H */
