#include <stdio.h>

void printArr(int *,int);

int main(void){
    //배열 변수도 포인터 변수다. 배열 변수(배열의 이름)는 배열의 참조값을 보관함.
    //그런데 포인터 변수와 한 가지 다른 점이 참조하는 대상을 변경할 수 없음.

    int num1 = 1;
    int num2 = 1;
    int * ptr1 = &num1;
    int * ptr2 = &num2;
    ptr1 = ptr2;//포인터 변수는 참조대상을 마음대로 바꿀 수 있음.

    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5};
    //arr1 = arr2;//참조 대상을 바꿀 수 없음.
    
    //이것을 "상수형태의 포인터" 라고 한다. 배열 변수는 상수형태의 포인터이다.

    //배열이 어떤식으로 해당 인덱스의 데이터에 접근하는지는 알지?
    //c언어에서 배열 변수는 배열의 첫번째 요소의 참조값을 가지고 있다.
    //그래서 배열변수[index] == 배열변수가 가지고 있는 첫번째 요소의 참조값 + 타입크기*index 이런 연산으로 매우 빠르게 해당 인덱스에 접근할 수 있다.
    //범위를 벗어나는 인덱스로 접근해도 컴파일 에러가 발생하지 않는 이유가 이것이다. c언어는 정말 단순하게 동작하는 것 같음.

    //직접 찍어보면 배열변수의 보관하고 있는 참조값과, 배열의 첫번째 요소의 참조값이 같고,
    //각 요소들의 참조값은 int형의 크기인 4씩 차이나는 것을 알 수 있다.
    printf("%p\n",arr1);
    for (int i = 0; i < 5; i++)
    {
        printf("%p\n",&arr1[i]);
    }


    //근데 앞에서 배열변수도 포인터변수라고 하지 않았나? 즉 포인터변수도 배열을 참조할 수 있다는거다.
    //요소에 인덱스로 접근하는 것도 배열변수가지고 하던 것과 똑같음.
    ptr1 = arr1;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",ptr1[i]);
    }

    //c언어에서 배열을 인수로 넘길때는 포인터변수를 매개변수로 쓰면 된다는 것이다.
    //근데 c언어에서는 len(arr) arr.length이런게 없어서 인수로 배열의 길이도 따로 넣어줘야 하네ㅋㅋ
    printArr(arr1,sizeof(arr1)/sizeof(arr1[0]));

    return 0;
}

void printArr(int * ptr, int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d\n",ptr[i]);
    }
}
