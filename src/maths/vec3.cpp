#include "vec3.h"

namespace cesaoEngine
{
    namespace maths
    {

        vec3::vec3()
        {
            mX = 0.0f;
            mY = 0.0f;
            mZ = 0.0f;
        }

        vec3::vec3(const float &pX, const float &pY, const float &pZ)
        {
            this->mX = pX;
            this->mY = pY;
            this->mZ = pZ;
        }

        // Todas as implementações de operadoes aritmeticos básicos
        // irão retornar uma referencia da própria struct que esta sendo manipulada
        // permitindo encaderar outros operadores
        vec3 &vec3::add(const vec3 &pOther)
        {
            mX += pOther.mX;
            mY += pOther.mY;
            mZ += pOther.mZ;

            return *this;
        }

        vec3 &vec3::subtract(const vec3 &pOther)
        {
            mX -= pOther.mX;
            mY -= pOther.mY;
            mZ -= pOther.mZ;

            return *this;
        }
        vec3 &vec3::multiply(const vec3 &pOther)
        {
            mX *= pOther.mX;
            mY *= pOther.mY;
            mZ *= pOther.mZ;

            return *this;
        }
        vec3 &vec3::divide(const vec3 &pOther)
        {
            mX /= pOther.mX;
            mY /= pOther.mY;
            mZ /= pOther.mZ;

            return *this;
        }

        vec3 &operator+(vec3 pLeft, const vec3 &pRight)
        {
            return pLeft.add(pRight);
        }

        vec3 &operator-(vec3 pLeft, const vec3 &pRight)
        {
            return pLeft.subtract(pRight);
        }

        vec3 &operator*(vec3 pLeft, const vec3 &pRight)
        {
            return pLeft.multiply(pRight);
        }

        vec3 &operator/(vec3 pLeft, const vec3 &pRight)
        {
            return pLeft.divide(pRight);
        }

        vec3 &vec3::operator+=(const vec3 &pOther)
        {
            return add(pOther);
        }

        vec3 &vec3::operator-=(const vec3 &pOther)
        {
            return subtract(pOther);
        }

        vec3 &vec3::operator/=(const vec3 &pOther)
        {
            return divide(pOther);
        }

        vec3 &vec3::operator*=(const vec3 &pOther)
        {
            return multiply(pOther);
        }

        bool vec3::operator==(const vec3 &pOther)
        {
            return mX == pOther.mX && mY == pOther.mY && mZ == pOther.mZ;
        }

         bool vec3::operator!=(const vec3 &pOther)
         {
             return !(*this == pOther);
         }

        std::ostream &operator<<(std::ostream &pStream, const vec3 &pVec)
        {
            pStream << "vec3: (" << pVec.mX << ", " << pVec.mY << ", "<< pVec.mZ << ")";

            return pStream;
        }
    }
}