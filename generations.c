#include <stdio.h>
#include <unistd.h>

int arrayX = 8;
int arrayY = 8;

void initializeArray(int array[arrayX][arrayY])
{
    int i,j,tmp = 0;

    for(i = 0; i < arrayX; i++)
    {
        for(j = 0; j < arrayY; j++)
        {
            if(i == 0 || i == arrayX - 1)
            {
                array[i][j] = 0;
            }
            else if(j == 0 || j == arrayY - 1)
            {
                array[i][j] = 0;
            }
            else
            {
                array[i][j] = tmp;
            }

            if(i % 2 == 0)
            {
                tmp++;
            }
            else
            {
                tmp--;
            }
        }
    }
}

void printArray(int array[arrayX][arrayY])
{
    int i,j = 0;
    int sum = 0;


    for(i = 1; i < arrayX - 1; i++)
    {
        for(j = 1; j < arrayY - 1; j++)
        {
            sum = sum + array[i][j];
            sum = sum + array[i-1][j];
            sum = sum + array[i+1][j];
            sum = sum + array[i][j+1];
            sum = sum + array[i-1][j+1];
            sum = sum + array[i+1][j+1];
            sum = sum + array[i][j-1];
            sum = sum + array[i-1][j-1];
            sum = sum + array[i+1][j-1];

            if(sum % 10 == 0)
            {
                printf("\033[22;34m%2d ",array[i][j]);
            }
            else if(sum < 50)
            {
                printf("\033[22;32m%2d ",array[i][j]);
            }
            else if(sum >=50 && sum < 150)
            {
                printf("\033[01;33m%2d ",array[i][j]);
            }
            else
            {
                printf("\033[22;31m%2d ",array[i][j]);
            }

            sum = 0;
        }
        printf("\n");
    }

    printf("\n\n");
    sleep(1);
}

void update(int A[arrayX][arrayY], int B[arrayX][arrayY])
{
    int i,j = 0;
    int sum = 0;

    //update B from A
    for(i = 1; i < arrayX - 1; i++)
    {
        for(j = 1; j < arrayY - 1; j++)
        {
            sum = sum + A[i][j];
            sum = sum + A[i-1][j];
            sum = sum + A[i+1][j];
            sum = sum + A[i][j+1];
            sum = sum + A[i-1][j+1];
            sum = sum + A[i+1][j+1];
            sum = sum + A[i][j-1];
            sum = sum + A[i-1][j-1];
            sum = sum + A[i+1][j-1];

            if(sum % 10 == 0)
            {
                B[i][j] = 0;
            }
            else if(sum < 50)
            {
                B[i][j] = A[i][j] + 3;
            }
            else if(sum >=50 && sum < 150)
            {
                if(A[i][j] > 2)
                    B[i][j] = A[i][j] - 3;
                else
                    B[i][j] = A[i][j];
            }
            else
            {
                B[i][j] = 1;
            }

            sum = 0;
        }
    }

    printArray(B);
    //update A from B
    for(i = 1; i < arrayX - 1; i++)
    {
        for(j = 1; j < arrayY - 1; j++)
        {
            sum = sum + B[i][j];
            sum = sum + B[i-1][j];
            sum = sum + B[i+1][j];
            sum = sum + B[i][j+1];
            sum = sum + B[i-1][j+1];
            sum = sum + B[i+1][j+1];
            sum = sum + B[i][j-1];

            if(sum % 10 == 0)
            {
                A[i][j] = 0;
            }
            else if(sum < 50)
            {
                A[i][j] = B[i][j] + 3;
            }
            else if(sum >=50 && sum < 150)
            {
                if(B[i][j] > 2)
                    A[i][j] = B[i][j] - 3;
                else
                    A[i][j] = B[i][j];
            }
            else
            {
                A[i][j] = 1;
            }

            sum = 0;
        }
    }

    printArray(A);
}
int main(void)
{
    int A[arrayX][arrayY];
    int B[arrayX][arrayY];
    int i = 0;

    initializeArray(A);
    initializeArray(B);

    printArray(A);
    while(i < 5)
    {
        update(A,B);
        i++;
    }

    return 0;
}
