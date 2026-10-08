/************************************************************************
 * Filename: minimat.c
 * Author: Gabi Heuser
 * Date: 10/1/2026
 * Description:
 *      Deals with the parsing and user interface of the main program
 * Returns: 0 unless quitting program.
 ************************************************************************/
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 #include "minimat.h"
 #include "vectorMath.h"
 #include "vectorStorage.h"
 #include "vectorStruct.h"


 int minimat(void){
    //input string
    char stringIn[100];

    //tokens for fgets()
    char* token1;
    char* token2;
    char* token3;
    char* token4;
    char* token5;

    //vectors from parsing
    vect v1, v2, v3;

    //number for future scalar multiplication
    double num = 0.0;

    //prompt user
    printf("minimat> ");

    //get input
    fgets(stringIn, 100, stdin);
    stringIn[strlen(stringIn)-1] = '\0';

    token1 = strtok(stringIn, " \n");

    //check if empty
    if (!token1){
        return 0;
    }

    //check one word commands

    if(!strcmp(token1, "quit")){
        printf("Quitting program...\n");
        return -1;
    } else if (!strcmp(token1, "clear")){
        clearVects();
        printf("Vectors cleared.\n");
        return 0;
    } else if (!strcmp(token1, "list")){
        printf("List of vectors:\n");
        listVects();
        return 0;
    } else{
        token2 = strtok(NULL, " \n");
        token3 = strtok(NULL, " \n");
        token4 = strtok(NULL, " \n");
        token5 = strtok(NULL, " \n");

        //no other token means must print first vector
        if(!token2){
            int vectorIndex = findVect(token1, &v1);
            if (vectorIndex >= 0){
                printVectByIndex(vectorIndex);
            } else {
                printf("Vector %s not found.\n", token1);
            }
            return 0;
        } else if (!strcmp(token2, "+") || !strcmp(token2, "-")){
            //must be adding or subtracting and reporting
            if (!token3 || token4){
                printf("Invalid expression");
                return 0;
            }

            int vect1i = findVect(token1, &v1);
            int vect2i = findVect(token3, &v2);
            if (vect1i < 0){
                printf("Vector %s not found\n", token1);
            } else if (vect2i < 0){
                printf("Vector %s not found\n", token3);
            } else {
                if (!strcmp(token2, "+")){
                    add(v1, v2, &v3);
                } else {
                    sub(v1, v2, &v3);
                }
                
                //print v3, using print method
                strcpy(v3.name, "ans");
                printVect(v3);
            }
            
            return 0;
        } else if (!strcmp(token2, "=")){
            //must be one of our equation types

            //if token 3 is empty, this was a failed assignment
            if (!token3 || !token4){
                printf("Invlaid assignment. Must be form: a = x y z\n");
                return 0;
            }


            //store name of first vector
            strcpy(v1.name, token1);

            if (!strcmp(token4, "+")){
                //vector addition
                
                //input validation
                if(!token5){
                    printf("Invalid expression.\n");
                    return 0;
                }

                //find and add vectors
                int vect2i = findVect(token3, &v2);
                int vect3i = findVect(token5, &v3);

                if (vect2i < 0){
                    printf("Vector %s not found.\n", token3);
                } else if (vect3i < 0){
                    printf("Vector %s not found.\n", token5);
                } else {
                    add(v2, v3, &v1);
                    //store in v1 and print
                    if (addVect(v1) >= 0){
                        printVect(v1);
                    } 
                }      

                return 0;
            } else if (!strcmp(token4, "-")){
                //vector subtraction

                //input validation
                if(!token5){
                    printf("Invalid expression.\n");
                    return 0;
                }

                //find and sub vectors
                int vect2i = findVect(token3, &v2);
                int vect3i = findVect(token5, &v3);

                if (vect2i < 0){
                    printf("Vector %s not found", token3);
                } else if (vect3i < 0){
                    printf("Vector %s not found", token5);
                } else {
                    sub(v2, v3, &v1);
                    //store in v1 and print
                    if (addVect(v1) >= 0){
                        printVect(v1);
                    }   
                }              

                return 0;
            } else if (!strcmp(token4, "*")){
                //vector scalar multiplication
                //must check both directions

                //input validation
                if(!token5){
                    printf("Invalid expression.\n");
                    return 0;
                }

                if (findVect(token3, &v2) >= 0 && isNum(token5, &num)){
                    //vector * number
                    mul(num, v2, &v1);
                } else if (isNum(token3, &num) && findVect(token5, &v2) >= 0){
                    //number * vector
                    mul(num, v2, &v1);
                } else {
                    printf("Invalid multiplication - Must input stored vector and a number.\n");
                    return 0;
                }

                //store in v1 and print
                if (addVect(v1) >= 0){
                    printVect(v1);
                }

                return 0;
            } else{
                //must be an assignment

                double x, y, z = 0.0;

                //input validation
                if (!token4 || !isNum(token3, &x) || !isNum(token4, &y) ||
                    (token5 && !isNum(token5, &z))){
                    printf("Invalid assignment. Must be form: name = x y z\n");
                    return 0;
                }

                //assign to v1
                v1.x = x;
                v1.y = y;
                v1.z = z;

                //save if we can
                if (addVect(v1) >= 0){
                    printVect(v1);
                }
            }
            return 0;
        } 




    }

    printf("Invalid expression.\n");
    return 0;
 }


 int isNum(char* string, double *num){
    char *end;
    *num = strtod(string, &end);
    return (end != string && *end == '\0');
 }