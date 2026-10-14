/************************************************************************
 * Filename: main.c
 * Author: Gabi Heuser
 * Date: 10/1/2026
 * Description:
 *      Main file for the minimat program. 
 *      Deals with the console and then hands work to other functions.
 * Compile: use Makefile: $ make -> $ ./main
 ************************************************************************/
 #include <stdio.h>
 #include <string.h>
 
 #include "minimat.h"
 #include "vectorStorage.h"
 #include "vectorMath.h"
 #include "vectorStruct.h"

 int main(int argc, char *argv[]){
   if (argc > 1 && !strcmp(argv[1], "-h")){
         printHelp();
         return 0;
       }


   printf("Welcome to minimat!\n");
   printf("Type \"help\" for a list of valid commands.\n");
   printf("Type \"quit\" to quit program.\n");


   int exitCode = 0;
   while(!exitCode){
      exitCode = minimat();
   }

    return 0;
 }