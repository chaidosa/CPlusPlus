#include<bits/stdc++.h>

class Graph{
    int n; //no fo vertices
    std::stack<int> order;
    std::map<int, bool> visited;
    std::map<int, std::list<int>> adj;
    std::map<int, std::list<int>> adjT; //list to strore adjacent vertices
    public:    
    void addEdge(int u, int v);  
   
    void fill_order(int v);
    void SCC();
    void DFSUtil(int v);
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adjT[v].push_back(u);
    visited[u] = false;
    visited[v] = false;
}

void Graph::fill_order(int v){
    
    std::list<int>::iterator i;
    visited[v] = true;
    for(i = adj[v].begin(); i!=adj[v].end(); i++)
        if(visited[*i] == false)
            fill_order(*i);    
    order.push(v);
    
}

void Graph::DFSUtil(int v){
    
    visited[v] = true;
    std::cout << v << " ";
    std::list<int>::iterator i;
     for(i = adjT[v].begin(); i!=adjT[v].end(); i++)
        if(visited[*i] == false)
            DFSUtil(*i);
}

void Graph::SCC(){
    
    for(auto i : adj){
        if(visited[i.first] == false)
            fill_order(i.first);
    }
    for(auto i : adj){
        visited[i.first] = false;
    }

    while (!order.empty())
    {
        if(!visited[order.top()]){
            DFSUtil(order.top());
            std::cout<<"\n";
        }
        order.pop();
    } 
}

int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(1, 4);
    g.addEdge(2, 6);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 7);
    g.addEdge(4, 5);
    g.addEdge(4, 0);
    g.addEdge(5, 6);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(7, 7);

    g.SCC();

}
