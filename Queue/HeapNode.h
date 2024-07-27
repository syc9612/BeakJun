#include <cstdio>

class HeapNode{
    int key;

    public:
    HeapNode(int k=0): key(k){}
    void setkey(int k){key = k;}
    int getkey(){return key;}
    void display(){printf("%4d", key);}
};