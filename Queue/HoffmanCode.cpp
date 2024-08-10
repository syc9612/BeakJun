#include "MinHeap.h"

void MakeTree(int freq[], int n){
    MinHeap heap;
    for(int i=0; i<n; i++){
        heap.insert( freq[i]);
    }
}