#ifndef VEC3_H 
#define VEC3_H

#include <cmath>
#include <cstdint>

using std::sqrt;
using std::int64_t;

class Vec3 {

    public:
        constexpr Vec3() : c{0,0,0} {};
        constexpr Vec3(double x, double y, double z) : c{x,y,z} {};

        constexpr double x() const noexcept { return c[0]; };
        constexpr double y() const noexcept { return c[1]; };
        constexpr double z() const noexcept { return c[2]; };

        constexpr Vec3 operator-() const noexcept { return Vec3(-c[0], -c[1], -c[2]); };
        constexpr double operator[](int i) const noexcept { return c[i]; };

        inline Vec3& operator+=(const Vec3& v) noexcept {
            this->c[0] += v.x();
            this->c[1] += v.y();
            this->c[2] += v.z();
            return *this;
        }

        inline Vec3& operator*=(const double t) noexcept {
            c[0] *= t;
            c[1] *= t;
            c[2] *= t;
            return *this;
        }

        inline Vec3& operator/=(const double t) noexcept {
            return *this *= 1/t;
        }
        
        constexpr double length_squared() const noexcept {
           return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; 
        }

        inline double length() {
            return sqrt(length_squared());                       
        }

    private:
        double c[3];

};	

using Point3 = Vec3;
using Color = Vec3;

#endif
