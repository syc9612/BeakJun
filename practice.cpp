#include <iostream>
#include <algorithm>

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
    return 0;
}