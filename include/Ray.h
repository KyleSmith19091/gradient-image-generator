#ifndef RAY_H 
#define RAY_H

#include "Vec3.h"
#include "Vec3Utils.h"

using namespace Vec3Utils;

class Ray{

    private:
        Point3 orig;
        Vec3 dir;

    public:
        constexpr Ray() {};
        constexpr Ray(const Point3 origin, const Vec3& direction) : orig(origin), dir(direction) {}; 

        constexpr Point3 origin() const { return orig; };
        constexpr Vec3 direction() const { return dir; };

        constexpr Point3 at(double t) const { return orig + (t * dir); };
        


    
};	
#endif
