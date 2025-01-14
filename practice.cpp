#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

int n,m;
int a_array[100000];
int temp;


//이진트리
void binary_search(int x){
    int left = 0, mid = 0 , right = n-1;

    while(left <= right){
        mid = (left + right) /2;

        //탈출 조건: a_array에서 x를 찾은 경우, 오름차순으로 정렬해야만 함.
        if(a_array[mid] == x){
            std::cout << 1 << std::endl;
            return;
        }
        else if(a_array[mid] > x){
            right = mid -1;
        }
        else{
            left = mid + 1;
        }

    }
    std:: cout<<0<<std::endl;
    return;
}

char* MakeStrAdr(int len){
    char* str =  (char*)malloc(sizeof(char)* len);
    return str;
}

int main(){
    //c 와 c++의 표준 stream의 동기화를 비활성화한다. : 시간절약 ,, 백준 전용이라 봐야함.
    std::ios_base::sync_with_stdio(0);
    //cin 과 cout이 하나라 묶어주는 과정: 시간 절약
    std::cin.tie(0);

    //전체 케이스 선언
    std::cin >> n;
    //배열에 숫자 입력
    for (int i=0;i<n; i++){
        std::cin >> a_array[i];
    
    }
    
    //오름차순 정렬.
    std::sort(a_array, a_array+n);

    int x;
    for(int i=0;i<m;i++){
        std::cin >> x;
        binary_search(x);
    }
    /*
    Subject: 길이정보를 인자로 받아서, 해당 길이의 문자열 저장이 가능한 배열을 생성하고, 그 배열의 주소 값을 반환하는 함수 정의해보기
    Date: 01/14
    */
   char* str=MakeStrAdr(20);
   strcpy(str, "I am so happy");
   std::cout << str << std::endl;
   free(str);

    return 0;
}