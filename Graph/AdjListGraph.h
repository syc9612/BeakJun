#include "Node.h"
#defne MAX_VTXS 256

class AdjListGraph{
    protected:
    int size;
    cahr vertices[MAX_VTXS];
    Node* adj[MAX_VTXS];
    
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
}