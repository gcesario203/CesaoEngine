#pragma once


#define _USE_MATH_DEFINES
#include "math.h"
#include "maths.h"

namespace cesaoEngine
{
    namespace maths
    {
        struct mat4
        {
            float mElements[4 * 4];

            mat4();
            mat4(float pDiagonal);

            mat4 &multiply(const mat4 &pOther);

            mat4 &operator*=(const mat4 &pOther);
            friend mat4 operator*(mat4 pLeft, const mat4 &pRight);

            static mat4 identity();

            static mat4 orthographic(float pLeft,
                                     float pRight,
                                     float pBottom,
                                     float pTop,
                                     float pNear,
                                     float pFar);

            static mat4 perspective(float pFov,
                                    float pAspectRatio,
                                    float pNear,
                                    float pFar);

            static mat4 translation(const vec3 &pTranslation);
            static mat4 rotation(float pAngle, const vec3 &pAxis);
            static mat4 scale(const vec3 &pScale);
        };

    }
}