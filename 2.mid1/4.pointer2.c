#include <stdio.h>

int main(void){
    //* 연산자로 포인터 변수가 담고있는 참조값이 가리키는 메모리 공간에 접근할 수 있다.
    int num1 = 10;
    int num2 = 10;

    int *ptr = &num1;
    printf("%d\n",*ptr);//10

    *ptr = 20;//num1 = 20;과 같음.
    printf("%d\n",*ptr);//20

    ptr = &num2;//참조 대상을 자유롭게 변경할 수 있음.

    //이 대목에서 포인터 변수의 타입이, 참조값을 담으려고 하는 변수의 타입과 같은 이유를 알 수 있다.
    //포인터 변수의 타입은 *로 메모리 공간에 접근할 때 접근 기준을 제공한다.
    //어디가 끝인지, 읽어온 다음에 정수형으로 해석해야할지, 실수형으로 해석해야할지를 알려줌.


    //포인터 사용 시 주의점. 
    //C언어는 포인터를 통해서 메모리에 직접 접근을 할 수 있게 하는 로우레벨 언어다.
    //자바나 파이썬이 인스턴스의 참조값을 복사해서 대입하고, 출력하고 하는 것과는 차원이 다름.
    //얘는 그냥 포인터 변수에 사용자가 직접 주소를 쳐 넣어서 접근을 해버릴 수가 있음.
    //그렇기 때문에 사용에 주의해야 한다.

    int * error;//선언만 하고 초기화 하지 않으면 쓰레기 값이 들어감.
    printf("%#x\n",error);//참조값이 출력됨.
    //*error = 10; 이렇게 사용자가 접근해서 아무 값이나 넣어버렸다가는 시스템이 다운되는 대참사가 벌어질 수 있다.

    error = 123;//이렇게 아무 값이나 막 집어넣는 것도 쓰레기 값을 집어넣는 것과 다를게 없음.

    //그래서 선언만 하고 대입은 나중에 하고 싶은 경우 NULL을 넣어두는 것이 안전하다. 자바의 null과 똑같은 듯.
    error = NULL;
    
    return 0;
}