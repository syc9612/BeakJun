#include <cstdio>
#define MAX_VTXS 256 //최대 정점 개수

class AdjMatGraph{
    protected:
    int size; //정점의 갯수
    char vertices[MAX_VTXS]; //정점의 이름
    int adj[MAX_VTXS][MAX_VTXS]; //인접행렬

    public:
    AdjMatGraph(){reset();}
    char getVertex(int i){return vertices[i];}
    int getEdge(int i,int j){return adj[i][j];}
    void setEdge(int i, int j, int val){ adj[i][j] = val;}

    bool isEmpty()[return size==0;]
    bool isFull(){retrun size >= MAX_VTXS;}

    void reset(){
        size = 0;
        for(int i=0;i<MAX_VTXS;i++)
            for(int j=0;j<MAX_VTXS;j++)
                setEdge(i,j,0);
    }

    void insertVertex(char name){
        is( !isFull()) vertices[size++] = name;
        else printf("ERROR: size over \n");
    }

    void insertEdge(int u, int v){
        setEdge(u,v,1);
        setEdge(v,u,1);
    }

    //how to file iostream??
    void load(char* filename){
        FILE* fp = fopen(filename, "r");
        if( fp != NULL){

            fclose(fp);
        }
        else{

        }
    }
    void store(char* filename){
        FILE* fp = fopen(filename, "w");

    }
}