#include "vec2.h"

namespace cesaoEngine
{
    namespace maths
    {

        vec2::vec2()
        {
            mX = 0.0f;
            mY = 0.0f;
        }

        vec2::vec2(const float &pX, const float &pY)
        {
            this->mX = pX;
            this->mY = pY;
        }

        // Todas as implementações de operadoes aritmeticos básicos
        // irão retornar uma referencia da própria struct que esta sendo manipulada
        // permitindo encaderar outros operadores
        vec2 &vec2::add(const vec2 &pOther)
        {
            mX += pOther.mX;
            mY += pOther.mY;

            return *this;
        }

        vec2 &vec2::subtract(const vec2 &pOther)
        {
            mX -= pOther.mX;
            mY -= pOther.mY;

            return *this;
        }
        vec2 &vec2::multiply(const vec2 &pOther)
        {
            mX *= pOther.mX;
            mY *= pOther.mY;

            return *this;
        }
        vec2 &vec2::divide(const vec2 &pOther)
        {
            mX /= pOther.mX;
            mY /= pOther.mY;

            return *this;
        }

        vec2 &operator+(vec2 pLeft, const vec2 &pRight)
        {
            return pLeft.add(pRight);
        }

        vec2 &operator-(vec2 pLeft, const vec2 &pRight)
        {
            return pLeft.subtract(pRight);
        }

        vec2 &operator*(vec2 pLeft, const vec2 &pRight)
        {
            return pLeft.multiply(pRight);
        }

        vec2 &operator/(vec2 pLeft, const vec2 &pRight)
        {
            return pLeft.divide(pRight);
        }

        vec2 &vec2::operator+=(const vec2 &pOther)
        {
            return add(pOther);
        }

        vec2 &vec2::operator-=(const vec2 &pOther)
        {
            return subtract(pOther);
        }

        vec2 &vec2::operator/=(const vec2 &pOther)
        {
            return divide(pOther);
        }

        vec2 &vec2::operator*=(const vec2 &pOther)
        {
            return multiply(pOther);
        }

        bool vec2::operator==(const vec2 &pOther)
        {
            return mX == pOther.mX && mY == pOther.mY;
        }

         bool vec2::operator!=(const vec2 &pOther)
         {
             return !(*this == pOther);
         }

        std::ostream &operator<<(std::ostream &pStream, const vec2 &pVec)
        {
            pStream << "vec2: (" << pVec.mX << ", " << pVec.mY << ")";

            return pStream;
        }
    }
}