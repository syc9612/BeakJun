#include <string>
#include <vector>
#include <algorithm> // min, max, sort

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
     // wallet과 bill의 길이를 정렬해 크기 순서대로 맞춘다.
    sort(wallet.begin(), wallet.end()); // wallet[0] <= wallet[1]
    sort(bill.begin(), bill.end());     // bill[0] <= bill[1]

    // bill의 크기를 wallet에 맞도록 줄인다.
    while (bill[0] > wallet[0] || bill[1] > wallet[1]) {
        if (bill[1] > wallet[1]) {
            // 긴 쪽을 반으로 접는다.
            bill[1] /= 2;
        } else {
            // 짧은 쪽을 반으로 접는다.
            bill[0] /= 2;
        }

        // 다시 정렬해 bill[0]이 짧은 쪽이 되도록 유지한다.
        sort(bill.begin(), bill.end());

        // 접은 횟수 증가
        answer++;
    }
    return answer;
}

