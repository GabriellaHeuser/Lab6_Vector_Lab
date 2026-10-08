/************************************************************************
 * Filename: vectorMath.c
 * Author: Gabi Heuser
 * Date: 10/1/2026
 * Description:
 *      Vector math operations returning vectors
 ************************************************************************/
 #include <stdio.h>
 #include <string.h>
 #include "minimat.h"
 #include "vectorMath.h"
 #include "vectorStorage.h"
 #include "vectorStruct.h"

 void add(vect a, vect b, vect *returnVect){
    returnVect->x = a.x + b.x;
    returnVect->y = a.y + b.y;
    returnVect->z = a.z + b.z;
 }
 void sub(vect a, vect b, vect *returnVect){
    returnVect->x = a.x - b.x;
    returnVect->y = a.y - b.y;
    returnVect->z = a.z - b.z;
 }

 void mul(double num, vect a, vect* returnVect){
    returnVect->x = a.x * num;
    returnVect->y = a.y * num;
    returnVect->z = a.z * num;
 }