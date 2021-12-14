#include "vec4.h"

namespace cesaoEngine
{
    namespace maths
    {

        vec4::vec4()
        {
            mX = 0.0f;
            mY = 0.0f;
            mZ = 0.0f;
            mW = 0.0f;
        }

        vec4::vec4(const float &pX, const float &pY, const float &pZ, const float &pW)
        {
            this->mX = pX;
            this->mY = pY;
            this->mZ = pZ;
            this->mW = pW;
        }

        // Todas as implementações de operadoes aritmeticos básicos
        // irão retornar uma referencia da própria struct que esta sendo manipulada
        // permitindo encaderar outros operadores
        vec4 &vec4::add(const vec4 &pOther)
        {
            mX += pOther.mX;
            mY += pOther.mY;
            mZ += pOther.mZ;
            mW += pOther.mW;

            return *this;
        }

        vec4 &vec4::subtract(const vec4 &pOther)
        {
            mX -= pOther.mX;
            mY -= pOther.mY;
            mZ -= pOther.mZ;
            mW -= pOther.mW;

            return *this;
        }
        vec4 &vec4::multiply(const vec4 &pOther)
        {
            mX *= pOther.mX;
            mY *= pOther.mY;
            mZ *= pOther.mZ;
            mW *= pOther.mW;

            return *this;
        }
        vec4 &vec4::divide(const vec4 &pOther)
        {
            mX /= pOther.mX;
            mY /= pOther.mY;
            mZ /= pOther.mZ;
            mW /= pOther.mW;

            return *this;
        }

        vec4 &operator+(vec4 pLeft, const vec4 &pRight)
        {
            return pLeft.add(pRight);
        }

        vec4 &operator-(vec4 pLeft, const vec4 &pRight)
        {
            return pLeft.subtract(pRight);
        }

        vec4 &operator*(vec4 pLeft, const vec4 &pRight)
        {
            return pLeft.multiply(pRight);
        }

        vec4 &operator/(vec4 pLeft, const vec4 &pRight)
        {
            return pLeft.divide(pRight);
        }

        vec4 &vec4::operator+=(const vec4 &pOther)
        {
            return add(pOther);
        }

        vec4 &vec4::operator-=(const vec4 &pOther)
        {
            return subtract(pOther);
        }

        vec4 &vec4::operator/=(const vec4 &pOther)
        {
            return divide(pOther);
        }

        vec4 &vec4::operator*=(const vec4 &pOther)
        {
            return multiply(pOther);
        }

        bool vec4::operator==(const vec4 &pOther)
        {
            return mX == pOther.mX && mY == pOther.mY && mZ == pOther.mZ && mW == pOther.mW;
        }

         bool vec4::operator!=(const vec4 &pOther)
         {
             return !(*this == pOther);
         }

        std::ostream &operator<<(std::ostream &pStream, const vec4 &pVec)
        {
            pStream << "vec4: (" << pVec.mX << ", " << pVec.mY << ", "<< pVec.mZ << ", "<<pVec.mW << ")";

            return pStream;
        }
    }
}