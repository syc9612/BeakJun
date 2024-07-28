class Heapnode{};

#include "HeapNode.h"
#define MAX_ELEMENT 200
 class MinHeap{
    HeapNode node[MAX_ELEMENT];
    int size;

    public:
    MinHeap(): size(0){}
    bool isEmpty(){return size ==0;}
    bool isFull(){return size == MAX_ELEMENT -1;}
 };