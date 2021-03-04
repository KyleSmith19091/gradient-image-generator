#ifndef VEC3_UTILS_H
#define VEC3_UTILS_H

#include "Vec3.h"

#include <ostream>

namespace Vec3Utils {
    
    inline std::ostream& operator<<(std::ostream& out, const Vec3& v) noexcept {
        return out << v.x() << " " << v.y() << " " << v.z();
    }

    constexpr Vec3 operator+(const Vec3& u, const Vec3& v) noexcept {
        return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
    }

    constexpr Vec3 operator-(const Vec3& u, const Vec3& v) noexcept {
        return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
    }

    constexpr Vec3 operator*(const Vec3& u, const Vec3& v) noexcept {
        return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
    }

    constexpr Vec3 operator*(const double t, const Vec3& v) noexcept {
        return Vec3(t * v.x(), t * v.y(), t * v.z());
    }

    constexpr Vec3 operator*(const Vec3& v, const double t) noexcept {
        return t * v;
    }

    constexpr Vec3 operator/(const Vec3& v, const double t) noexcept {
        return (1/t) * v;
    }

    inline Vec3 unit_vector(Vec3 v) { return v / v.length(); }

    constexpr double dot(const Vec3& u, const Vec3& v) noexcept {
      return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
    }

    constexpr Vec3 cross(const Vec3& u, const Vec3& v) noexcept {
      return Vec3(u.y() * v.z() - u.z() * v.y(), u.z() - v.x() - u.x() * v.z(),
                  u.x() * v.y() - u.y() * v.x());
    }

    constexpr Vec3 lerp(const Vec3& a, const Vec3& b, const double t) noexcept {
        return a + (b - a)*t;
    }
}

#endif
