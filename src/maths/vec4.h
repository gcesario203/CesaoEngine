#pragma once
#include <iostream>

namespace cesaoEngine
{
    namespace maths
    {
        struct vec4
        {
            float mX, mY, mZ, mW;

            vec4();

            // Contrutor da struct de vetores recebendo endereços de memoria
            vec4(const float &pX, const float &pY, const float &pZ, const float &pW);

            vec4 &add(const vec4 &pOther);
            vec4 &subtract(const vec4 &pOther);
            vec4 &multiply(const vec4 &pOther);
            vec4 &divide(const vec4 &pOther);

            // Vetor esquerdo só servira para criar um "clone" do valor
            // enquanto o vetor direito é quem de fato será modificado
            friend vec4 &operator+(vec4 pLeft ,const vec4 &pRight);
            friend vec4 &operator-(vec4 pLeft ,const vec4 &pRight);
            friend vec4 &operator*(vec4 pLeft ,const vec4 &pRight);
            friend vec4 &operator/(vec4 pLeft ,const vec4 &pRight);

            bool operator==(const vec4 &pOther);

            bool operator!=(const vec4 &pOther);

            vec4 &operator+=(const vec4 &pOther);
            vec4 &operator-=(const vec4 &pOther);
            vec4 &operator/=(const vec4 &pOther);
            vec4 &operator*=(const vec4 &pOther);

            friend std::ostream &operator<<(std::ostream &pStream, const vec4 &pVec);
        };

    }
}