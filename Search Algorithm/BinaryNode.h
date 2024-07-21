#include <cstdio>

class BinaryNode{
    protected:
    int data;
    BinaryNode* left; //왼쪽 서브노드의 포인터
    BinaryNode* right; //오른쪽 서브노드의 포인터
    
    public:
    //이진 노드의 기본 구성 및 기본선언.
    BinaryNode( int val =0, BinaryNode* l=NULL, BinaryNode* r=NULL) : data(val), left(l), right(r){    }

    void setData(int val){ data = val;}
    void setleft(BinaryNode* l){ left = l;}
    void setRight(BinaryNode* r){ right = r;}

    int getData(){return data;}
    BinaryNode* getLeft(){return left;}
    BinaryNode* getRight(){return right;}

    bool isLeaf(){return left==NULL && right==NULL;}
};