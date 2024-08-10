#include <cstdio>

void swap(int* px, int* py){
    printf("swap 호출하기 전 주소값: a =%#x , b=%#x \n", px, py);
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
    printf("swap 호출하기 후 주소값: a =%#x , b=%#x \n", px, py);
}

int main(){
    int a=1; int b=2;
    int* pa= &a; int* pb= &b;

    printf("swap 호출하기 전: a=%d, b=%d\n", a,b);
    
    swap(&a,&b);
    printf("swap 호출하기 후: a=%d, b=%d\n", a,b);
    
}