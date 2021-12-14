#pragma once
#include <iostream>

namespace cesaoEngine
{
    namespace maths
    {
        struct vec3
        {
            float mX, mY, mZ;

            vec3();

            // Contrutor da struct de vetores recebendo endereços de memoria
            vec3(const float &pX, const float &pY, const float &pZ);

            vec3 &add(const vec3 &pOther);
            vec3 &subtract(const vec3 &pOther);
            vec3 &multiply(const vec3 &pOther);
            vec3 &divide(const vec3 &pOther);

            // Vetor esquerdo só servira para criar um "clone" do valor
            // enquanto o vetor direito é quem de fato será modificado
            friend vec3 &operator+(vec3 pLeft ,const vec3 &pRight);
            friend vec3 &operator-(vec3 pLeft ,const vec3 &pRight);
            friend vec3 &operator*(vec3 pLeft ,const vec3 &pRight);
            friend vec3 &operator/(vec3 pLeft ,const vec3 &pRight);

            bool operator==(const vec3 &pOther);

            bool operator!=(const vec3 &pOther);

            vec3 &operator+=(const vec3 &pOther);
            vec3 &operator-=(const vec3 &pOther);
            vec3 &operator/=(const vec3 &pOther);
            vec3 &operator*=(const vec3 &pOther);

            friend std::ostream &operator<<(std::ostream &pStream, const vec3 &pVec);
        };

    }
}