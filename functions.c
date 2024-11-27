#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>



//проверка позиции на пропуск
int checkIfNull(int** matrix,int** posNulls,int amountNulls,int i, int j){
    for (int k = 0; k < amountNulls; k++)
    {
        if (i == *(*(posNulls+k)+0) && j == *(*(posNulls+k)+1))
        {
            return 1;
        }
    }
    return 0;
}

//сортировка позиций пробелов
void sort(int** posNulls, int amountNulls) {
    for (int i = 0; i < amountNulls; i++) {
        for (int j = 0; j < amountNulls - 1; j++) {
            if (*(*(posNulls + j) + 0) > *(*(posNulls + j + 1) + 0) ||
               (*(*(posNulls + j) + 0) == *(*(posNulls + j + 1) + 0) && 
                *(*(posNulls + j) + 1) > *(*(posNulls + j + 1) + 1))) {

                int temp0 = *(*(posNulls + j) + 0);
                int temp1 = *(*(posNulls + j) + 1);

                *(*(posNulls + j) + 0) = *(*(posNulls + j + 1) + 0);
                *(*(posNulls + j) + 1) = *(*(posNulls + j + 1) + 1);

                *(*(posNulls + j + 1) + 0) = temp0;
                *(*(posNulls + j + 1) + 1) = temp1;
            }
        }
    }
}


//проверка 1 из условий генерации матрицы (квадрат)
int check_square(int** matrix,int i,int j,int number,int SIZE){
    int sqrtSize = sqrt(SIZE);
    for (int n = i-(i%sqrtSize); n < i-(i%sqrtSize)+sqrtSize; n++)
    {
        for (int m = j-(j%sqrtSize); m < j-(j%sqrtSize)+sqrtSize; m++)
        {
            if (*(*(matrix+n)+m) == number)
            {
                return 0;
            }
            
        }
        
    }
    return 1;
    
}
//проверка 1 из условий генерации матрицы (строка)
int check_row(int** matrix,int i,int j,int number,int SIZE){
    for (int k = 0; k < SIZE; k++)
    {
        if (*(*(matrix+i) + k) == number)
        {
            return 0;
        }
        
    }
    return 1;
   
    
}
//проверка 1 из условий генерации матрицы (столбик)
int check_col(int** matrix,int i, int j, int number,int SIZE){
    for (int k = 0; k < SIZE; k++)
    {
        if (*(*(matrix+k) + j) == number)
        {
            return 0;
        }
        
    }
    return 1;
}

//строка построена верно?
int success_row(int** matrix,int i,int SIZE){
 
    
    for (int j = 0; j < SIZE; j++)
    {
        if (*(*(matrix+i) + j) == 0) 
        {
            return 0;
        }
        
        
    }
    
    return 1;
    
}

//удалить строку
void rmRow(int** matrix, int i,int SIZE){
    for (int m = 0; m < SIZE; m++)
    {
        *(*(matrix+i) + m) = 0;
    }
    
}

//удалить матрицу
void rmMatrix(int** matrix,int SIZE){
     for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            *(*(matrix+i) + j) = 0;
        }
    }

}


//проверка матрицы на отсутствие нулей
int good_matrix(int** matrix,int SIZE){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (*(*(matrix+i) +j) == 0)
            {
                return 0;
            }
            
        }
        
    }
    return 1;
    
}
//матрица верна?
int perfect_matrix(int** matrix,int** notPerfectMatrix,int SIZE){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (*(*(matrix+i)+j) != *(*(notPerfectMatrix+i)+j))
            {
                return 0;
            }
            
            
        }
        
    }
    return 1;
}
//вывод матрицы в user mode
void print_UserMatrix(int** matrix, int x, int y,int** posNulls, int amountNulls,int SIZE){
    printf("\033[H\033[J");
    
     for (int i = 0; i < SIZE; i++) {
        
        
        for (int j = 0; j < SIZE; j++) {
            
            
            
            if (*(*(matrix+i)+j) != 0 && (i!=x||j!=y) && checkIfNull(matrix,posNulls,amountNulls,i,j) == 1)
            {
                printf("\033[92m%d \033[0m",*(*(matrix+i)+j));
            }
            else if (*(*(matrix+i)+j) != 0 && (i!=x||j!=y))
            {
                printf("%d ",*(*(matrix+i)+j));
            }
            else if(i==x  && j == y && *(*(matrix+i)+j) == 0)
            {
                printf("\033[92m[.]\033[0m");
            }
            else if (i==x && j==y && *(*(matrix+i)+j) != 0)
            {
                printf("[%d]",*(*(matrix+i)+j));
            }
            
            else
            {
                printf(". " );
            }
            // if (SIZE == 9)
            // {
            //     if ((j+1) %3 == 0)
            //     {
            //         printf("%c ",'|');
            //     }
            // }
            // if (SIZE == 4)
            // {
            //     if((j+1)%2==0){
            //         printf("%c",'|');
            //     }
            // }
            
            
            
            
            
           
        }
       
        
        printf("\n");
        

        // if (SIZE == 9)
        // {
        //     if ((i+1)%3==0)
        //     {
        //         printf("%c %c %c ",'-','-' ,'-');
        //         printf("%c %c %c ",'-','-' ,'-');
        //         printf("%c %c %c ",'-','-' ,'-');
        //         printf("%c %c %c \n",'-','-' ,'-');
        //     }
        // }

        // if (SIZE == 4)
        // {
        //     if ((i+1)%2==0)
        //     {
        //         printf("%c%c %c%c %c%c %c%c\n",'-','-','-','-','-','-','-','-');
        //     }
            
        // }
               

            
            
            

        
        
    }
}

//вывод матрицы в общем случае
void print_matrix(int** matrix,int** posNulls,int amountNulls,int SIZE) {
    printf("\033[H\033[J");
    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {
            if (*(*(matrix+i) + j) == 0)
            {
                printf("%c ",'.');
            }
            else if(*(*(matrix+i)+j) != 0 && checkIfNull(matrix,posNulls,amountNulls,i,j) == 1)
            {
                printf("\033[92m%d \033[0m", *(*(matrix+i) + j));
            }
            else
            {
                printf("%d ",*(*(matrix+i)+j));
            }
            
            
            
        }
        printf("\n");
    }
    fflush(stdout);
}

//брут форс решение
void force(int** matrix,int** posNulls,int amountNulls,int SIZE,int** notPerfectMatrix){
    int a = 1;
    for (int i = 0; i < amountNulls; i++)
    {
        
        int checkforce = 0;
        print_matrix(matrix,posNulls,amountNulls,SIZE);
        usleep(100000);    
        
        while (checkforce == 0)
        { 
            
            int checkI = *(*(posNulls+i)+0);
            int checkJ = *(*(posNulls+i)+1);
            *(*(matrix+checkI)+checkJ) = a;
            print_matrix(matrix,posNulls,amountNulls,SIZE);
            usleep(100000);
            *(*(matrix+checkI)+checkJ) = 0;
            if (check_col(matrix,checkI,checkJ,a,SIZE) + check_row(matrix,checkI,checkJ,a,SIZE)+check_square(matrix,checkI,checkJ,a,SIZE) ==3)
            {
                *(*(matrix+checkI)+checkJ) = a;
                a = 1;
                checkforce = 1;

            }
            
            else{
                a++;
                if (a>  9)
                {
                    
                    i-=1;
                    checkI = *(*(posNulls+i)+0);
                    checkJ = *(*(posNulls+i)+1);
                    i--;
                    if (*(*(matrix+checkI)+checkJ) == 9)
                    {
                        *(*(matrix+checkI)+checkJ) = 1;
                        i--;
                    }
                    else{
                        *(*(matrix+checkI)+checkJ)+=1;
                    }

                    a = *(*(matrix+checkI)+checkJ);
                    checkforce = 1;
                    break;
                }
                
               
            
                // *(*(matrix+checkI)+checkJ) = a;
            }
            if (perfect_matrix(matrix,notPerfectMatrix,SIZE) == 1)
            {   
                exit;
            }
        
        }
        
        
        
    }
    
    
    
    
    
    
        
        
}

//генерация матрицы  
void fill_matrix(int** matrix,int SIZE){
    
    int trueMatrix = 0;
    int cnt = 0;
    while(trueMatrix == 0){
        rmMatrix(matrix,SIZE);
        for (int i = 0; i < SIZE ; i++)
        {
            int trueRow = 0;
            cnt = 0;
            while (trueRow == 0) 
            {
                for (int j = 0; j < SIZE; j++)
                {
                int num = rand()%SIZE + 1;
                if (check_col(matrix,i,j,num,SIZE) + check_row(matrix,i,j,num,SIZE) + check_square(matrix,i,j,num,SIZE) == 3)
                {
                    *(*(matrix+i) + j) = num;
                }
                
                }
                // if (cnt >= 100)
                // {
                //     rmMatrix(matrix);
                // }
                
                if (success_row(matrix,i,SIZE) == 0)
                {
                    rmRow(matrix,i,SIZE);
                    cnt++;
                    
                    
                    
                }
                else
                {
                    trueRow = 1;
                }
                // printf("%d\n",cnt);
            }
        }
        // if (good_matrix(matrix) == 1)
        // {
            trueMatrix = 1;
        // }
        
        
        
    }
    
    
          
}

//проверка нулей на уникальность
int check_unique(int** posNulls,int i, int j,int amountNulls){
    for (int a = 0; a < amountNulls; a++)
    {
        if (*(*(posNulls+a) + 0) == i && *(*(posNulls+a)+ 1) == j)
        {
            return  0;
        }
        
    }
    return 1;
}          




            
//расставляем пробелы
void addNulls(int** matrix,int** posNulls,int amountNulls,int SIZE){
    
    int cnt = 0;
    int n = 0;
    while (cnt!=amountNulls)
    {
        int i = rand()%SIZE;
        int j = rand()%SIZE;
        if (check_unique(posNulls,i,j,amountNulls) == 1)
        {
            cnt++;
            *(*(matrix+i) + j) = 0;
            *(*(posNulls+n)+0) = i;
            *(*(posNulls+n)+1) = j;
            
            n++;
        }
        
    }
    sort(posNulls,amountNulls);

    
}
//поставить значение в матрицу и вернуть ее
int** setValue(int** matrix,int i,int j,int value){
    *(*(matrix+i)+j) = value;
    return matrix;
}

//очистка памяти
void freeAll(int** matrix,int** posNulls,int amountNulls,int** notPerfectMatrix,int SIZE){

    for (int i = 0; i < SIZE; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < amountNulls; i++)
    {
        free(posNulls[i]);
    }
    free(posNulls);

    for (int i = 0; i < SIZE; i++)
    {
        free(notPerfectMatrix[i]);
    }
    free(notPerfectMatrix);
}



//user mode
void userDesicion(int **matrix,int** posNulls,int amountNulls,int** notPerfectMatrx,int SIZE){
    struct termios newtio;
    struct termios oldtio;
    tcgetattr(STDIN_FILENO, &oldtio);
    newtio = oldtio;
    newtio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newtio);
    char c;
    
    int i = 0;
    int globalCheck = 0;
    int checkValue = 0;
    while (globalCheck == 0)
    {
        checkValue = 0;
        while (checkValue == 0) {
            int checkI = *(*(posNulls+i)+0);
            int checkJ = *(*(posNulls+i)+1);
            
            print_UserMatrix(matrix,checkI,checkJ,posNulls,amountNulls,SIZE);
            c = getchar(); 
            if (c-'0' > 0 && c-'0' <10)
            {
                setValue(matrix,checkI,checkJ,c-'0');
                print_UserMatrix(matrix,checkI,checkJ,posNulls,amountNulls,SIZE);
                checkValue = 1;
            }
            
            if (c == 'd' || c == 'D')
            {
                if (i+1 != amountNulls)
                {
                    i++;
                    
                }
            }
            else if (c == 'a' || c == 'A')
            {
                if ((i>0))
                {
                    i--;
                }  
            }
            if (c == 'q' || c == 'Q')
            {
                globalCheck = 1;
                tcsetattr(STDIN_FILENO, TCSANOW, &oldtio); 
                break;
            }
            if (c == 0x7f)
            {
                setValue(matrix,checkI,checkJ,0);
            }
        }
        if (perfect_matrix(matrix,notPerfectMatrx,SIZE) == 1)
        {
            globalCheck = 1;
            tcsetattr(STDIN_FILENO, TCSANOW, &oldtio); 
            print_matrix(matrix,posNulls,amountNulls,SIZE);
            break;
        }
    }
}
