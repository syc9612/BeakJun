#inlcude "AdjListGraph.h"

class SrchALGrpah : public AdjListGraph{
    bool visited[MAX_VTXS]; //check the visited node

    public:
    void resetVisited(){
        for(int i=0; i<size ; i++){
            visited[i] == false;
        }
    }
    bool isLinked(int u, int v){
        for( Node* p=adj[u]l p!=NULL; p=p->getLink()){
            if(p->getId() == v) return true;
        }
        return false
    }

    void DFS(int v){
        visited[v] = true;
        printf("%c", getVertex(v));

        for( Node* p=adj[v] ; p!=NULL ; p=p->getLink()){
            if(visited[p->getID()] == false){ //if node p is visited
                DFS(p->getID()); //DFS restart on the 'w' node
            }
        }
    }

};