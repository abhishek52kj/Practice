#include <bits/stdc++.h>

using namespace std;
 
class Graph
{
    int V;    
    list<int> *adj;    
    void DFSUtil(int v, bool visited[]);
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    bool isCyclicUtil(int v, bool visited[], bool *recStack); 
public:
    Graph(int V);   
    void addEdge(int v, int w);
    void topologicalSort();
    bool isCyclic(); 
    void DFS();   
    void BFS();   
};

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
 
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    }
 
    Stack.push(v);
}
 
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
 

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  
    return false;
}
 
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
 
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
}
 
void Graph::DFS()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

void Graph::BFS()
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            list<int> queue;
 
            visited[i] = true;
            queue.push_back(i);
    
            while(!queue.empty())
            {
                i = queue.front();
                cout << i << " ";
                queue.pop_front();
 
                for (auto it = adj[i].begin(); it != adj[i].end(); it++)
                {
                     if (!visited[*it])
                    {
                        visited[*it] = true;
                        queue.push_back(*it);
                    }
                }
            }
        }    
    }
}

 
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal : ";
    g.DFS();
    cout << "\nFollowing is Breadth First Traversal : ";
    g.BFS();
 
    return 0;
}