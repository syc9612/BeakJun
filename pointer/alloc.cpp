#include <cstdio>

//2차원 배열 동적 할당 함수
int** alloc2DINT (int rows, int cols){
    if( rows <= 0 || cols <= 0) return NULL;

    int** mat = new int* [rows]; //포인터 변수를 저장할 배열
    for( int i=0; i<rows; i++){
        mat[i] = new int [cols];
    }
    return mat;
}
//2차원 배열 동적 해제 함수
void free2DINT(int **mat, int rows, int cols=0){
    if( mat != NULL){
        for(int i=0; i<rows; i++){
            delete [] mat[i];
        }
        delete [] mat;
    }
}
//함수 포인터
void foo( int a){
    printf("foo: %d\n", a);
}

//클래스의 객체를 포인터로 조작하기 위한 structure 선언
struct MyNewType{
    int i;
    float f;
};

void main( void ){
//new, delete 활용을 통한 동적 할당 예
    char * str;
    int num=1000;

    str = new char [num];
    if( str == NULL){
        printf("Insufficient memory available \n");
    }
    else {
        printf(" Allocated 1000 bytes\n");
        delete [] str;
        printf(" Memory Free \n");

    }

//클래스의 객체를 포인터로 조작
    MyNewType s;
    MyNewType* ps;

    ps = &s;
    ps->i = 2;
    ps->f = 3.14f;

    printf("i: %d, f: %f", ps->i, ps->f);

//f는 함수의 주소를 담는 포인터 타입.
    void (*f)(int);

    f=foo;
    f(10);
    (*f)(10);

    //결과 foo(10) == f(10) == (*f)(10)
}