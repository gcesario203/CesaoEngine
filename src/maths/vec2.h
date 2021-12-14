#pragma once
#include <iostream>

namespace cesaoEngine
{
    namespace maths
    {
        struct vec2
        {
            float mX, mY;

            vec2();

            // Contrutor da struct de vetores recebendo endereços de memoria
            vec2(const float &pX, const float &pY);

            vec2 &add(const vec2 &pOther);
            vec2 &subtract(const vec2 &pOther);
            vec2 &multiply(const vec2 &pOther);
            vec2 &divide(const vec2 &pOther);

            // Vetor esquerdo só servira para criar um "clone" do valor
            // enquanto o vetor direito é quem de fato será modificado
            friend vec2 &operator+(vec2 pLeft ,const vec2 &pRight);
            friend vec2 &operator-(vec2 pLeft ,const vec2 &pRight);
            friend vec2 &operator*(vec2 pLeft ,const vec2 &pRight);
            friend vec2 &operator/(vec2 pLeft ,const vec2 &pRight);

            bool operator==(const vec2 &pOther);

            bool operator!=(const vec2 &pOther);

            vec2 &operator+=(const vec2 &pOther);
            vec2 &operator-=(const vec2 &pOther);
            vec2 &operator/=(const vec2 &pOther);
            vec2 &operator*=(const vec2 &pOther);

            friend std::ostream &operator<<(std::ostream &pStream, const vec2 &pVec);
        };

    }
}