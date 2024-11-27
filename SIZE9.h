#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

void addNulls(int** matrix,int** posNulls,int amountNulls,int SIZE);

void userDesicion(int **matrix,int** posNulls,int amountNulls,int** notPerfectMatrx,int SIZE);

void force(int** matrix,int** posNulls,int amountNulls,int SIZE,int** notPerfectMatrix);

void freeAll(int** matrix,int** posNulls,int amountNulls,int** notPerfectMatrix,int SIZE);

void rmMatrix(int** matrix,int SIZE);

int check_col(int** matrix,int i, int j, int number,int SIZE);

int check_row(int** matrix,int i,int j,int number,int SIZE);

int check_square(int** matrix,int i,int j,int number,int SIZE);

void rmRow(int** matrix, int i,int SIZE);

int success_row(int** matrix,int i,int SIZE);

int check_unique(int** posNulls,int i, int j,int amountNulls);

void sort(int** posNulls, int amountNulls);

void print_UserMatrix(int** matrix, int x, int y,int** posNulls, int amountNulls,int SIZE);

int** setValue(int** matrix,int i,int j,int value);

int perfect_matrix(int** matrix,int** notPerfectMatrix,int SIZE);



