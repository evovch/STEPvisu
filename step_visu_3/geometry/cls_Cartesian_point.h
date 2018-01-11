/**
 * ISO 10303-42-2000
 * 4.4.4 cartesian_point
 */

#pragma once

#include "geometry/cls_Point.h" // mother class

namespace nspGeometry
{
    class cls_Cartesian_point : public cls_Point
    {
    public:
        cls_Cartesian_point();
        cls_Cartesian_point(double p_x, double p_y, double p_z);
        ~cls_Cartesian_point();

        /**
        * Метод для выброса информации в командную строку. Полезно для debug'а.
        */
        void Dump(void) const;

        double GetX(void) const { return mX; }
        double GetY(void) const { return mY; }
        double GetZ(void) const { return mZ; }

    private:
        double mX;
        double mY;
        double mZ;

    };
} // End of namespace nspGeometry
