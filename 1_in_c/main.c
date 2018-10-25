#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXINPUT 100

int isValid(char input[]){
    int length = strlen(input);
    for (int i = 0; i < length; ++i)
        if (!isdigit(input[i]))
        {
            return 0;
        }
    return 1;
}

int main() {
    int n1,m1,n2,m2;
    char input[MAXINPUT] = "";

    printf("How many rows will first matrix have?\n");
    scanf("%s", input);
    if(isValid(input) == 1){
        sscanf(input, "%d", &n1);
        //printf("%d", n1);
    }
    else{   //input is not valid
        while(isValid(input) == 0) {
            printf("Provide a number!\n");
            scanf("%s", input);
        }
        sscanf(input, "%d", &n1);
    }

    printf("How many columns will first matrix have?\n");
    scanf("%s", input);
    if(isValid(input) == 1){
        sscanf(input, "%d", &m1);
        //printf("%d", m1);
    }
    else{   //input is not valid
        while(isValid(input) == 0) {
            printf("Provide a number!\n");
            scanf("%s", input);
        }
        sscanf(input, "%d", &m1);
    }

    printf("How many rows will second matrix have?\n");
    scanf("%s", input);
    if(isValid(input) == 1){
        sscanf(input, "%d", &n2);
        //printf("%d", n2);
    }
    else{   //input is not valid
        while(isValid(input) == 0) {
            printf("Provide a number!\n");
            scanf("%s", input);
        }
        sscanf(input, "%d", &n2);
    }

    printf("How many columns will second matrix have?\n");
    scanf("%s", input);
    if(isValid(input) == 1){
        sscanf(input, "%d", &m2);
        //printf("%d", m2);
    }
    else{   //input is not valid
        while(isValid(input) == 0) {
            printf("Provide a number!\n");
            scanf("%s", input);
        }
        sscanf(input, "%d", &m2);
    }

    // check the condition to multiply matrices
    if(m1 != n2){
        printf("Bad dimensions.");
        return 0;
    }

    int ar1[n1][m1], ar2[n2][m2], res[n1][m2];

    printf("Provide numbers in the first matrix: \n");

    for(int i = 0; i < n1; ++i){
        for(int j = 0; j < m1; ++j) {
            scanf("%s", input);
            if(isValid(input) == 1){
                sscanf(input, "%d", &ar1[i][j]);
                //printf("%d", m2);
            }
            else{   //input is not valid
                while(isValid(input) == 0) {
                    printf("Provide a number!\n");
                    scanf("%s", input);
                }
                sscanf(input, "%d", &ar1[i][j]);
            }
        }
    }

    printf("Provide numbers in the second matrix: \n");

    for(int i = 0; i < n2; ++i){
        for(int j = 0; j < m2; ++j){
            scanf("%s", input);
            if(isValid(input) == 1){
                sscanf(input, "%d", &ar2[i][j]);
                //printf("%d", m2);
            }
            else{   //input is not valid
                while(isValid(input) == 0) {
                    printf("Provide a number!\n");
                    scanf("%s", input);
                }
                sscanf(input, "%d", &ar2[i][j]);
            }
        }
    }

    //initialize whole result array to 0
    for(int i = 0; i < n1; ++i)
        for(int j = 0; j < m2; ++j)
            res[i][j] = 0;

    //multiply first and second matrix and store the value into result array
    for(int i = 0; i < n1; ++i)
    {
        for(int j = 0; j < m2; ++j)
        {
            for(int k=0; k < m1; ++k)
            {
                res[i][j] += ar1[i][k] * ar2[k][j];
            }
        }
    }

    //display the result
    printf("\nFinal matrix: \n");
    for(int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            printf("%d", res[i][j]);
            printf("\t");
        }
        printf("\n");
    }


    return 0;
}