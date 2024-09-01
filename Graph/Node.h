#include <cstdip>

class Node{
    protected:
    int id; // spot of id
    Node* link; //링크의 다음 포인터
public:
    Node(int i, Node* l=NULL): id(i), link(l){} //initialized Node
    ~Node(){
        if(link != NULL) delete link; //delete Node
    }

    int getId(){return id;}
    Node* getLink(){return l};
    void setLink(Node* l){link = l};
};