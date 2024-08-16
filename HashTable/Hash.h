#include <iostream>

#define MAX_TABLE 8191
#define MAX_KEY 64

/*
다른 자료형의 별명을 만들기 위해 사용된다.
int, double 고 ㅏ같은 자료형들을 사용자가 원하는 의도에 맞게 다른 의름을 부여하고 싶을때 사용
*/
typedef long long ll;

typdef struct HASH{
    char key[MAX_KEY + 1];
    int data;
}HASH;


HASH table[MAX_TABLE];


/*
1. Hash 값을 왼쪽으로 5번 비트연산
2. 원본 HASH 값을 더한다
3. 한 문자의 ASCII 값을 더한다.
4. 위 결과를 모든 문자에 대해 반복한다.
5. 최종 값이 해시테이블의 범위를 벗어나면, 나머지 연산을 취해준다.
*/
ll hashGen(char key[]){
    //특정 소수 값 지정
    ll h = 5381;
    while (*key != '\0')
        h = (((h << 5) + h) + *key++) % MAX_TABLE;
    return h;
}

int m_strcmp(const char * str1, const char* str2){
    while 
}