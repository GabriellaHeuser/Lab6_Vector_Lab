/************************************************************************
 * Filename: vectorStorage.c
 * Author: Gabi Heuser
 * Date: 10/1/2026
 * Description:
 *      vector stoarage functions
 ************************************************************************/
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "minimat.h"
 #include "vectorMath.h"
 #include "vectorStorage.h"
 #include "vectorStruct.h"

 #define NUMVECTORS 10

 static vect vectors[NUMVECTORS];

 int addVect(vect v){
   int emptyIndex = -1;
   for (int i = 0; i < NUMVECTORS; i++){
      if (vectors[i].name[0] == '\0'){
         if (emptyIndex == -1){
            emptyIndex = i;
         }
      } else if (!strcmp(vectors[i].name, v.name)){
         vectors[i] = v;
         return i;
      }
   }
   if (emptyIndex == -1){
      printf("Memory full.\n");
      return -1;
   }
   vectors[emptyIndex] = v;
   return emptyIndex;
}

 int findVect(const char *name, vect *out){
   for (int i = 0; i < NUMVECTORS; i++){
      if (vectors[i].name[0] != '\0' && !strcmp(vectors[i].name, name)){
         *out = vectors[i];
         return i;
      }
   }
   return -1;
}

void clearVects(void){
   for (int i = 0; i < NUMVECTORS; i++){
      vectors[i].name[0] = '\0';
      vectors[i].x = 0.0;
      vectors[i].y = 0.0;
      vectors[i].z = 0.0;
   }
}

void listVects(void){
   for (int i = 0; i < NUMVECTORS; i++){
      if (vectors[i].name[0] != '\0'){
         printVectByIndex(i);
      }
   }
}

void printVectByIndex(int index){
   printf("%s = %.2f %.2f %.2f\n", vectors[index].name,
          vectors[index].x, vectors[index].y, vectors[index].z);
}

void printVect(vect v){
   printf("%s = %.2f %.2f %.2f\n", v.name, v.x, v.y, v.z);
}