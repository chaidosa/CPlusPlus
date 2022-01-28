#include<bits/stdc++.h>

using namespace std;

class Graph{
    private:
        int n; //number of vertices
        list<int>*adj; //pointer to list of adjacent vertices 
    public:
        Graph(int n);
        void addEdge(int u, int v);
        void BFS(int s);
};

Graph::Graph(int n){
    this->n = n;
    adj = new list<int>[n];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::BFS(int s){
    bool visited[n]; //visited to keep track of vertex already visited

    for(int i = 0; i < n; i++)
        visited[i] = false;

    queue<int>Q; //queue to vertex to be explored
    visited[s] = true;
    Q.push(s);
    list<int>::iterator i;
    while (!Q.empty())
    {
        int cur_v = Q.front();
        cout<<cur_v<<" ";
        Q.pop();

        for(i = adj[cur_v].begin(); i!= adj[cur_v].end(); i++){

            if(!visited[*i]){
                
                visited[*i] = true;
                Q.push(*i);
            }
        }
    }
    
}

int main(){
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    cout<<"Breadth first traversal: \n";
    g.BFS(2);
}

