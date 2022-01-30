#include<bits/stdc++.h>

 
class Graph{
    int n; //no fo vertices
    
    std::map<int, bool> visited;
    std::list<int> topo;
    std::map<int, std::list<int> > adj; //list to strore adjacent vertices
    public:    
    void addEdge(int u, int v);
    void TopologicalSort();
    void DFSUtil(int v);
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    visited[u] = false;
    visited[v] = false;    
}


void Graph::DFSUtil(int v){
    //This function is called after starting vertex
    visited[v] = true;
    
    std::list<int>::iterator i;
     for(i = adj[v].begin(); i!=adj[v].end(); i++)
        if(visited[*i] == false)
            DFSUtil(*i);    
    topo.push_front(v);    
     
}

void Graph::TopologicalSort(){
     for(auto i : adj)
        if(visited[i.first] == false){          
            DFSUtil(i.first);
        }
    
    std::cout<<"Topological sort: ";
    for(auto i : topo)
        std::cout<<i<<" ";

}

int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    g.addEdge(4, 3);
    g.addEdge(4, 6);
    g.addEdge(6, 5);
    g.addEdge(5, 7);

    g.TopologicalSort();
}