#include <stdio.h>

const int size = 4;

void printArr(int arr[][4]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");  
    }
}

void rotateArr(int (*ptr) [size]){
    
    int newArr[size][size];

    for (int k = 0; k < 4; k++)
    {
        

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                newArr[j][size-1-i] = ptr[i][j];
            }
        }
        
        printArr(newArr);
        printf("\n");

        // Copy newArr back to arr
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                ptr[i][j] = newArr[i][j];
            }
        }
    }
}

int main(void){
    //4*4 크기의 2차원 배열을 오른쪽으로 90도씩 회전시켜야 함.
    int arr[size][size];

    int num = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = num++;
        }  
    }

    rotateArr(arr);
    
    return 0;
}