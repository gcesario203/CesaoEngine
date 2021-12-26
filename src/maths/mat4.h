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

            // Atributos relacionados a estrutura da matriz, sendo <mElements>,
            // a matriz e suas posições em si, e o <mColumns>, um indexador
            // para retornar de um modo elegante as colunas da matriz.
            // EX: mColumns[0] irá retornar os elementos de mElements da posição
            // 0 até 4, mColumns[1] irá retornar os membros da matriz da posição
            // 4 até 8
            union
            {
                float mElements[4 * 4];
                vec4 mColumns[4];
            };

            // Contrutor padrão da matriz, preenchendo todos os valores com 0.0f
            mat4();

            // Construtor da matriz passando o valor como float da matriz principal
            mat4(float pDiagonal);

            // Multiplicação de matrizes, passando como parametro, outra raiz
            mat4 &multiply(const mat4 &pOther);

            // Operador de multiplicação e atribuição
            mat4 &operator*=(const mat4 &pOther);

            // Operador de multiplicação
            friend mat4 operator*(mat4 pLeft, const mat4 &pRight);

            // Retorna uma nova matriz, passando o valor 1.0f nas diagonais principais
            static mat4 identity();

            // Visão Ortografica(pegar apostila de desenho técnico) da matriz,
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