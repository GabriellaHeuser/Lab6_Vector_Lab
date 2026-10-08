/************************************************************************
 * Filename: vectorMath.h
 * Author: Gabi Heuser
 * Date: 10/1/2026
 * Description:
 *      Header file for vector math
 ************************************************************************/
 #include "vectorStruct.h"

 #ifndef VECTORMATH_H
 #define VECTORMATH_H


 void add(vect a, vect b, vect *returnVect);
 void sub(vect a, vect b, vect *returnVect);
 void mul(double num, vect a, vect *returnVect);

 #endif