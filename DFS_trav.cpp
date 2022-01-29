#include<bits/stdc++.h>

class Graph{
    int n; //no fo vertices
    std::map<int, bool> visited;
    std::map<int, std::list<int>> adj; //list to strore adjacent vertices
    public:    
    void addEdge(int u, int v);
    void DFS();
    void DFSUtil(int v);
};



void Graph::addEdge(int u, int v){
    // This function adds the edge from vertex u to v
    adj[u].push_back(v);
}

void Graph::DFS(){
    // This is called first time for the starting vertex
    for(auto i : adj)
        if(visited[i.first] == false)
            DFSUtil(i.first);

}

void Graph::DFSUtil(int v){
    //This function is called after starting vertex
    visited[v] = true;
    std::cout << v << " ";
    std::list<int>::iterator i;
     for(i = adj[v].begin(); i!=adj[v].end(); i++)
        if(visited[*i] == false)
            DFSUtil(*i);
}

int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    g.DFS();// dfs on vertices 0;
}