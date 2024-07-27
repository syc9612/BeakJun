#include "HeapNode.h"
#define MAX_ELEMENT 200

/*
1. 완전 이진 트리이다. -> 중간에 비어있는 요서 없음. 배열의 인덱스로 생각
2. 왼쪽자식의 인덱스 = 부모의 인덱스*2
3. 오른쪽자식의 인덱스 = 부모의 인덱스*2 +1
*/
class MaxHeap{
    HeapNode node[MAX_ELEMENT];
    int size;

    public:
    MaxHeap() : size(0){}
    bool isEmpty(){return size == 0;}
    bool isFull(){return size == MAX_ELEMENT;}

    HeapNode& getParent(int i){ return node[i/2];}
    HeapNode& getLeft(int i){ return node[i*2];}
    HeapNode& getRight(int i){ return node[i*2 +1];}

    void insert(int key){
        if(isFull()) return;
        int i = ++size;

        while( i!=1 //루트 아니고
                && key>getParent(i).getkey()){ //부모 노드보다 키값이 크면
                    node[i] = getParent(i); //교환

                    i /=2;
                }
        node[i].setkey(key);
    }

    HeapNode remove(){
        if(isEmpty()) return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        int parent =1;
        int child =2;
        while(child <= size){
            if( child < size
                && getLeft(parent).getkey() < getRight(parent).getkey())
                child++;
            if(last.getkey() >= node[child].getkey()) break;

            node[parent] = node[child];
            parent = child;
            child *= 2;
        }

        node[parent] = last;
        return item;
        

    }
    HeapNode find(){return node[1];}

    void display(){
        for(int i=1, level=1;i<=size;i++){
            if(i== level){
                printf("\n");
                level *=2;
            }
            node[i].display();
        }
        printf("\n----------------------------------------");
    }
    
};