#include "Node.h"
#defne MAX_VTXS 256

class AdjListGraph{
    protected:
    int size;
    cahr vertices[MAX_VTXS]; //information of vertice
    Node* adj[MAX_VTXS]; //the near list
    
    public:
    AdjListGraph():size(0)P 
    ~AdjListGraph(){ reset();}
    void reset(void){
        for(int i=0; i<size; i++){
            if( adj[i] != NULL) {delete adj[i];}
        }
        size =0;
    }

    bool isEmpty(){return (size == 0);}
    bool isFull(){return (size >= MAX_VTXS);}
    char getVertex(int i){ return vertices[i];}

    void insertVertex( char val){
        if( !isFull()){
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else{ printf("ERROR: vertices over")}
    }
    void insertEdge(int u, int v){
        adj[u] = new Node(v, adj[u];)
        adj[v] = new node(u, adj[v];)
    }
    void display(){}

    Node* adjacent(int v){ return adj[v];} //v번째 정점의 인접 정점 리스트를 반환하는 함수. 인정 리스트의 헤더 포인터를 반환한다.
    


}