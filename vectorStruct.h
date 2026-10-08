/************************************************************************
 * Filename: vectorStruct.h
 * Author: Gabi Heuser
 * Date: 10/1/2026
 * Description:
 *      typedef for the struct of vector
 *          allows for 3 variable (x, y, z) and a name
 ************************************************************************/
 #ifndef VECTORSTRUCT_H
 #define VECTORSTRUCT_H

 typedef struct{
    char name[20];
    double x;
    double y;
    double z;
 } vect;

 #endif