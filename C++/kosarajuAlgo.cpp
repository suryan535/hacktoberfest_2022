#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int nodes;
	list<int> *adj;
	list<int> *revAdj;
public:
	Graph(int n)
	{
		nodes=n;
		adj=new list<int> [nodes];
		revAdj=new list<int> [nodes];
	}

	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}
    
    void dfsUtil(int u,vector<bool> &visited,stack<int> &st)
    {
    	visited[u]=true;

    	for(auto it:adj[u])
    	{
    		if(visited[it]==false)
    		{
    			dfsUtil(it,visited,st);
    		}
    	}

    	st.push(u);
    }
    
    void revGraph()
    {
    	for(int i=0;i<nodes;i++)
    	{
    		for(auto it:adj[i])
    		{
    			revAdj[it].push_back(i);
    		}
    	}
    }

    void dfsPrint(int u,vector<bool> &visited)
    {
    	visited[u]=true;
    	cout<<u<<" ";
    	for(auto it:revAdj[u])
    	{
          if(visited[it]==false)
          {
          	dfsPrint(it,visited);
          }
    	}
    }
	void printScc()
	{
		vector<bool> visited(nodes,false);
		stack<int> st;

		for(int i=0;i<nodes;i++)
		{
			if(visited[i]==false)
			{
				dfsUtil(i,visited,st);
			}
		}

		//Reversing the Graph
		revGraph();
        for(auto it:visited) it=false;

       while(st.empty()==false){
          if(visited[st.top()]==false)
          {
          	dfsPrint(st.top(),visited);
          	cout<<"\n";
          }
          st.pop();
       }
	}
};

int main()
{
	Graph g(5);
 g.addEdge(1, 0);
 g.addEdge(0, 2); 
 g.addEdge(2, 1); 
 g.addEdge(0, 3); 
 g.addEdge(3, 4); 
  
  g.printScc();
   return 0;
}