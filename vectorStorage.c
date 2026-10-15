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
 #include "vectorStorage.h"
 #include "vectorMath.h"
 #include "vectorStruct.h"

 #define INITIAL_CAPACITY 10

 static int numVectors = 0;

 static vect *vectors = NULL;

 int addVect(vect v){
   //does our array exist yet?
   if (vectors == NULL){
      vectors = calloc(INITIAL_CAPACITY, sizeof(vect));
      if (vectors == NULL){
         printf("Memory unavailable. \n");
         return -1;
      }
      numVectors = INITIAL_CAPACITY;
   }


   //checking for open space in array
   int emptyIndex = -1;
   for (int i = 0; i < numVectors; i++){
      if (vectors[i].name[0] == '\0'){
         if (emptyIndex == -1){
            emptyIndex = i;
         }
      } else if (!strcmp(vectors[i].name, v.name)){
         vectors[i] = v;
         return i;
      }
   }

   //no space, must reallocate
   if (emptyIndex == -1){
      int newSize = numVectors * 2;
      vect *revect = realloc(vectors, newSize*sizeof(vect));
      if (revect == NULL){
         printf("Memory unavailable. \n");
         return -1;
      }
      
      vectors = revect;
      

      //initialize new space to zeros
      for (int i = numVectors; i < newSize; i++){
         vectors[i].name[0] = '\0';
         vectors[i].x = 0;
         vectors[i].y = 0;
         vectors[i].z = 0;
      }

      emptyIndex = numVectors;
      numVectors = newSize;
   }

   vectors[emptyIndex] = v;
   return emptyIndex;
}

 int findVect(const char *name, vect *out){
   for (int i = 0; i < numVectors; i++){
      if (vectors[i].name[0] != '\0' && !strcmp(vectors[i].name, name)){
         *out = vectors[i];
         return i;
      }
   }
   return -1;
}

void clearVects(void){
   free(vectors);
   vectors = NULL;
   numVectors = 0;
}

void listVects(void){
   for (int i = 0; i < numVectors; i++){
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

int load(char *filename){
   if (!isCSV(filename)){
      printf("Must enter .csv file. \n");
      return 1;
   }

   FILE *fd = fopen(filename, "r");
   if (fd == NULL){
      printf("File \"%s\" not found. \n", filename);
      return 1;
   }

   char line[256];

   while (fgets(line, sizeof(line), fd)){
      int lineLength = strlen(line);
      while (lineLength > 0 && (line[lineLength - 1] == '\n' || line[lineLength - 1] == '\r')){
         line[lineLength - 1] = '\0';
         lineLength--;
      }

      if (lineLength > 0){
         char* tok1 = strtok(line, ",");
         char* tok2 = strtok(NULL, ",");
         char* tok3 = strtok(NULL, ",");
         char* tok4 = strtok(NULL, ",");
         char* tok5 = strtok(NULL, ",");

         if (!tok1 || !tok2 || !tok3 || !tok4 || tok5){
             printf("Invalid file format. \n");
             fclose(fd);
             return -1;
         }

         vect v;
         strncpy(v.name, tok1, sizeof(v.name) - 1);
         v.name[sizeof(v.name) - 1] = '\0';
         v.x = atof(tok2);
         v.y = atof(tok3);
         v.z = atof(tok4);
         addVect(v);
      }
   }

   fclose(fd);
   return 0;
}


int save(char *filename){
   if (!isCSV(filename)){
      printf("Must enter .csv file. \n");
      return 1;
   }

   FILE *fd = fopen(filename, "w");
   if (fd == NULL){
      printf("Error opening file. \n");
      return 1;
   }

   for (int i = 0; i < numVectors; i++){
      if (vectors[i].name[0] != '\0'){
         fprintf(fd, "%s,%f,%f,%f\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
      }
   }

   fclose(fd);
   return 0;
}

int isCSV(char *filename){
   if (strlen(filename) < 4){
      return 0;
   }

   return !strcmp(filename + strlen(filename) - 4, ".csv");

}