#include "BinaryNode.h"
/*
전위: 루트 - 왼 - 오
중위: 왼 - 루트 - 오
후위: 왼 - 오 - 루트
*/
class BinaryTree{
    BinaryNode* root;
    public:
    BinaryTree(): root(NULL){}
    void setRoot(BinaryNode* node){ root = node;}
    BinaryNode* getRoot(){return root;}

    bool isEmpty(){return root == NULL;}

    void inorder(){printf("\n  inorder: "); inorder(root);}
    void inorder(BinaryNode* node){ //재귀함수
        if( node != NULL){
            inorder(node -> getLeft()); //재귀로 왼쪽노드들 쭉 출력
            printf("[%c]", node->getData());
            inorder(node->getRight());
        }
    }
};