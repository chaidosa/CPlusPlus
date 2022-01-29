#include<bits/stdc++.h>

class Graph{
    int n; //no fo vertices
    std::list<int>*adj; //list to strore adjacent vertices
    public:
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int s);
    void DFSUtil(int v, bool* visited);
};

Graph::Graph(int v){
    this->n = v;
    this->adj = new std::list<int>[v];
}

void Graph::addEdge(int u, int v){
    // This function adds the edge from vertex u to v
    adj[u].push_back(v);
}

void Graph::DFS(int s){
    // This is called first time for the starting vertex
    bool visited[n];
    for(int i = 0; i < n; ++i)
        visited[i] = false;
    std::cout<<"DFS traversal: \n"<< s <<" ";
    visited[s] = true;
    std::list<int>::iterator i;
    for(i = adj[s].begin(); i!=adj[s].end(); i++)
        if(visited[*i] == false)
            DFSUtil(*i, visited);  

}

void Graph::DFSUtil(int v, bool * visited){
    //This function is called after starting vertex
    visited[v] = true;
    std::cout << v << " ";
    std::list<int>::iterator i;
     for(i = adj[v].begin(); i!=adj[v].end(); i++)
        if(visited[*i] == false)
            DFSUtil(*i, visited);
}

int main(){
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    g.DFS(0);// dfs on vertices 0;
}