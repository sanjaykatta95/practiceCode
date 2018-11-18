#include <bits/stdc++.h>
using namespace std;
#define long long int ll

class Graph
{
	int V;
	list<int> *adj;
	public:
		Graph(int V)
		{
			this->V=V;
			adj = new list<int>[V];
		}
		void addEdge(int u,int v)
		{
			adj[u].push_back(v);
		}
		void BFS(int s)
		{
			bool *visited = new bool[V];
			memset(visited,false,sizeof(visited));
			queue<int> q;
			q.push(s);
			visited[s]=true;
			list<int>::iterator it;
			while(!q.empty())
			{
				int s = q.front();
				q.pop();
				cout<<s<<" ";
				for(it= adj[s].begin();it!=adj[s].end();it++)
				{
					if(!visited[*it])
					{
						q.push(*it);
						visited[*it]=true;
					}
				}
			}
			cout<<endl;
		}
		
		void dfsUtil(int s,bool *visited)
		{
			visited[s]=true;
			cout<<s<<" ";
			for(list<int>::iterator it = adj[s].begin();it!=adj[s].end();it++)
			if(!visited[*it])
			dfsUtil(*it,visited);
		}
		
		void dfs(int s)
		{
			bool *visited = new bool[V];
			memset(visited,false,sizeof(visited));
			dfsUtil(s,visited);
		}
		
		bool isCyclicUtil(int s,bool *visited,bool *recStack)
		{
			if(!visited[s])
			{
				visited[s] = true;
				recStack[s] = true;
				list<int>::iterator it;
				for(it = adj[s].begin();it!=adj[s].end();it++)
				{
					if(!visited[*it]&&isCyclicUtil(*it,visited,recStack))
						return true;
					else if(recStack[*it])
						return true;
				}
			}
			recStack[s]=false;
			return false;
		}
		
		bool isCyclic()
		{
			bool *visited = new bool[V];
			bool *recStack = new bool[V];
			memset(visited,false,sizeof(visited));
			memset(recStack,false,sizeof(recStack));
			list<int>::iterator it;
			for(int i=0;i<V;i++)
				if(isCyclicUtil(i,visited,recStack))
					return true;
			return false;
		}
		
};

int main()
{
	ios_base::sync_with_stdio(false);
//	Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);
// 
//    cout << "Following is Breadth First Traversal "
//         << "(starting from vertex 2) \n";
//    g.BFS(2);
//    g.dfs(2);
// 
//    return 0;
	 Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}

