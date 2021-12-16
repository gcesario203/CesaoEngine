#include "mat4.h"

namespace cesaoEngine
{
    namespace maths
    {
        mat4::mat4()
        {
            for (int i = 0; i < 4 * 4; i++)
            {
                mElements[i] = 0.0f;
            }
        }

        mat4::mat4(float pDiagonal)
        {
            for (int i = 0; i < 4 * 4; i++)
            {
                if (i >= 0 && i <= 3)
                {
                    mElements[i + i * 4] = pDiagonal;
                }
                else
                {
                    mElements[i] = 0.0f;
                }
            }
        }

        mat4 mat4::identity()
        {
            return mat4(1.0f);
        }

        mat4 &mat4::multiply(const mat4 &pOther)
        {
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 4; x++)
                {
                    float sum = 0.0f;
                    for (int e = 0; e < 4; e++)
                    {
                        sum += mElements[x + e * 4] * pOther.mElements[e + y * 4];
                    }

                    mElements[x + y * 4] = sum;
                }
            }

            return *this;
        }
        mat4 operator*(mat4 pLeft, const mat4 &pRight)
        {
            return pLeft.multiply(pRight);
        };

        mat4 &mat4::operator*=(const mat4 &pOther)
        {
            return multiply(pOther);
        };

        mat4 mat4::orthographic(float pLeft,
                                float pRight,
                                float pBottom,
                                float pTop,
                                float pNear,
                                float pFar)
        {
            mat4 result(1.0f);

            result.mElements[0 + 0 * 4] = 2.0f / (pRight - pLeft);
            result.mElements[1 + 1 * 4] = 2.0f / (pTop - pBottom);
            result.mElements[2 + 2 * 4] = 2.0f / (pNear - pFar);

            result.mElements[0 + 3 * 4] = (pLeft + pRight) / (pLeft - pRight);
            result.mElements[1 + 3 * 4] = (pBottom + pTop) / (pBottom - pTop);
            result.mElements[2 + 3 * 4] = (pFar + pNear) / (pFar - pNear);

            return result;
        };

        mat4 mat4::perspective(float pFov,
                               float pAspectRatio,
                               float pNear,
                               float pFar)
        {
            mat4 result(1.0f);

            float q = 1.0f / tan(toRadians(0.5f * pFov));
            float a = q / pAspectRatio;

            float b = (pNear + pFar) / (pNear - pFar);
            float c = (2.0f * pNear * pFar) / (pNear - pFar);

            result.mElements[0 + 0 * 4] = a;
            result.mElements[1 + 1 * 4] = q;
            result.mElements[2 + 2 * 4] = b;
            result.mElements[3 + 2 * 4] = -1.0f;
            result.mElements[2 + 3 * 4] = c;

            return c;
        };

        mat4 mat4::translation(const vec3 &pTranslation)
        {
            mat4 result(1.0f);

            result.mElements[0 + 3 * 4] = pTranslation.mX;
            result.mElements[1 + 3 * 4] = pTranslation.mY;
            result.mElements[2 + 3 * 4] = pTranslation.mZ;

            return result;
        };

        mat4 mat4::scale(const vec3 &pScale)
        {
            mat4 result(1.0f);

            result.mElements[0 + 0 * 4] = pScale.mX;
            result.mElements[1 + 1 * 4] = pScale.mY;
            result.mElements[2 + 2 * 4] = pScale.mZ;

            return result;
        }

        mat4 mat4::rotation(float pAngle, const vec3 &pAxis)
        {
            mat4 result(1.0f);

            float r = toRadians(pAngle);
            float c = cos(r);
            float s = sin(r);
            float omc = 1.0f - c;

            float x = pAxis.mX;
            float y = pAxis.mY;
            float z = pAxis.mZ;

            result.mElements[0 + 0 * 4] = x * omc + c;
            result.mElements[1 + 0 * 4] = y * x * omc + z * s;
            result.mElements[2 + 0 * 4] = x * z * omc - y * s;

            result.mElements[0 + 1 * 4] = x * y * omc - z * s;
            result.mElements[1 + 1 * 4] = y * omc + c;
            result.mElements[2 + 1 * 4] = y * z * omc + x * s;

            result.mElements[0 + 2 * 4] = x * z * omc + y * s;
            result.mElements[1 + 2 * 4] = y * z * omc - x * s;
            result.mElements[2 + 2 * 4] = z * omc + c;

            return result;
        };

    }
}