/************************************************************************
 * Filename: vectorStorage.h
 * Author: Gabi Heuser
 * Date: 10/1/2026
 * Description:
 *      header file for vector storage
 ************************************************************************/
 #ifndef VECTORSTORAGE_H
 #define VECTORSTORAGE_H
 
 int  addVect(vect v);
 int  findVect(const char *name, vect *out);
 void clearVects(void);
 void listVects(void);
 void printVectByIndex(int index);
 void printVect(vect v);

 #endif
 
