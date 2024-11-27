#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#include "SIZE4.h"
#include "SIZE9.h"

int main(){
    int SIZE;
    int mode;
    puts("Выберите размер игрового поля: ");
    scanf("%d",&SIZE);
    if (SIZE != 9 && SIZE != 4)
    {
        puts("Размер поля может быть либо 4, либо 9");
        exit;
    }
    if (SIZE == 4)
    {
        #include "SIZE4.h"
    }
    else
    {
        #include "SIZE9.h"
    }
    
    
    puts("Выберите игровой режим:");
    puts("0 - user mode, 1 - brute force");
    scanf("%d",&mode);
    
    srand(time(NULL));
    int** matrix = 0;
    matrix = (int**)malloc(sizeof(int*) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*SIZE);
    }
    if (SIZE == 9)
    {
        int array[9][9] = {{5,3,9,8,7,6,4,1,2},{7,2,8,3,1,4,9,6,5},{6,4,1,2,9,5,7,3,8},{4,6,2,5,3,9,8,7,1},{3,8,5,7,2,1,6,4,9},{1,9,7,4,6,8,2,5,3},{2,5,6,1,8,7,3,9,4},{9,1,3,6,4,2,5,8,7},{8,7,4,9,5,3,1,2,6}};
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                *(*(matrix+i)+j) = array[i][j];
            }
            
        }
        int amountNulls = SIZE*SIZE*3/10+2;
        int** posNulls = 0;  
        posNulls = (int **) malloc(amountNulls* sizeof(int *) );
        for (int i=0; i<amountNulls; i++) 
        {
            posNulls[i] = (int *) malloc(2* sizeof(int) );

        }
        int** notPerfectMatrix = 0;
        notPerfectMatrix = (int**)malloc(sizeof(int*)*SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            notPerfectMatrix[i] = (int*)malloc(sizeof(int)*SIZE);
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                *(*(notPerfectMatrix+i)+j) = array[i][j];
            }
            
        }
        addNulls(matrix, posNulls,amountNulls,SIZE);
        if (mode == 0)
        {
            userDesicion(matrix,posNulls,amountNulls,notPerfectMatrix,SIZE);
        }
        else if(mode == 1)
        {
            force(matrix,posNulls,amountNulls,SIZE,notPerfectMatrix);
        }
        freeAll(matrix,posNulls,amountNulls,notPerfectMatrix,SIZE);
    }





    if (SIZE == 4)
    {
        fill_matrix(matrix,SIZE); 
        int amountNulls = SIZE*SIZE*3/10+2; 
        int** posNulls = 0;  
        posNulls = (int **) malloc(amountNulls* sizeof(int *) );
        for (int i=0; i<amountNulls; i++) 
        {
            posNulls[i] = (int *) malloc(2* sizeof(int) );

        }
         int** notPerfectMatrix = 0;
        notPerfectMatrix = (int**)malloc(sizeof(int*)*SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            notPerfectMatrix[i] = (int*)malloc(sizeof(int)*SIZE);
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                *(*(notPerfectMatrix+i)+j) = *(*(matrix+i)+j);
            }
            
        }

        addNulls(matrix, posNulls,amountNulls,SIZE);
        if (mode == 0)
        {
            userDesicion(matrix,posNulls,amountNulls,notPerfectMatrix,SIZE);
        }
        else if(mode == 1)
        {
            force(matrix,posNulls,amountNulls,SIZE,notPerfectMatrix);
        }
        freeAll(matrix,posNulls,amountNulls,notPerfectMatrix,SIZE);
        

    }
    

}