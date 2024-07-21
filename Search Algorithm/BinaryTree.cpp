#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <chrono>    // for time measurement
#include <BinaryTree_header.h>

using namespace std;
using namespace std::chrono;

// 선형 탐색 함수
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // 타겟 값을 찾으면 인덱스를 반환
        }
    }
    return -1;  // 타겟 값을 찾지 못하면 -1 반환
}

// 이진 탐색 함수
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // 타겟 값을 찾으면 인덱스를 반환
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // 타겟 값을 찾지 못하면 -1 반환
}

int main() {
    vector<int> dataSizes = {1000, 10000, 100000, 1000000};
    int target = -1; // 찾을 수 없는 값 (탐색의 최악 경우를 보기 위해)
    
    for (int size : dataSizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = i;
        }

        // 선형 탐색 시간 측정
        auto start = high_resolution_clock::now();
        linearSearch(arr, target);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Linear Search for size " << size << ": " << duration << " microseconds" << endl;

        // 이진 탐색 시간 측정 (배열은 이미 정렬되어 있음)
        start = high_resolution_clock::now();
        binarySearch(arr, target);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start).count();
        cout << "Binary Search for size " << size << ": " << duration << " microseconds" << endl;
    }

    return 0;
}

/*
1. 모든 노드는 유일한 키를 갖는다
2. 왼쪽 서브트리의 키들은 루트의 키보다 작다
3. 오른쪽 서브트리의 키들은 루트의 키보다 작다.
4. 왼쪽과 오른쪽 서브트리도 이진 탐색 트리이다. 
*/

