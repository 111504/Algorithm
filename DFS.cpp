#include <iostream>
#include <list>

using namespace std;
class Grapth{
    int V;
    list<int>  *adj;
    
    void DFS_Util(int v,bool visited[]);
    
    public:
       Grapth(int V);
       
       void addEdge(int v,int w);
       
       void DFS(int v);
    
};

Grapth::Grapth(int V){
    this->V=V;
    adj=new list<int>[V];
    
}

void Grapth::addEdge(int v,int w){
    
    adj[v].push_back(w);
}

void Grapth::DFS_Util(int v,bool visited[]){
    visited[v]=true;
    cout<<v<<" ";
    
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if (!visited[*i]) 
            DFS_Util(*i, visited);
        
    }
    
}
void Grapth::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFS_Util(v, visited); 
} 


int main() 
{ 
    // Create a graph given in the above diagram 
    Grapth g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0; 
} 