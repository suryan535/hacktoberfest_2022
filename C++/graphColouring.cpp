#include<bits/stdc++.h>
using namespace std;

class Graph
{
  private:
  	int nodes;
  	list<int> *adj;
  public:
  	Graph(int v)
  	{
  		nodes=v;
  		adj=new list<int> [nodes];
  	}

  	void addEdge(int u,int v)
  	{
  		adj[u].push_back(v);
  		adj[v].push_back(u);
  	}

  	void greedyColoring()
  	{
  		int result[nodes];
  		for(int i=0;i<nodes;i++) result[i]=-1;
  		result[0]=0;

  		bool available[nodes];
  		for(int i=0;i<nodes;i++) available[i]=false;
        
        list<int>::iterator it;

  		for(int i=1;i<nodes;i++)
  		{
          for(it=adj[i].begin();it!=adj[i].end();it++)
          {
          	if(result[*it]!=-1)
          	{
          		available[result[*it]]=true;
          	}
          }

          int cr;
          for(int j=0;j<nodes;j++)
          {
          	if(available[j]==false)
          	{
          		cr=j;
               break;
          	}
          }

          result[i]=cr;
          for(it=adj[i].begin();it!=adj[i].end();it++)
          {
          	if(result[*it]!=-1)
          	{
          		available[result[*it]]=false;
          	}
          }

  		}

  		//Printing
  		for(int i=0;i<nodes;i++) cout<<result[i]<<" ";
  		cout<<"\n";	
  	}
};
int main()
{
	Graph g1(5); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 3); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 4); 
    cout << "Coloring of graph 1 \n"; 
    g1.greedyColoring(); 
  
    Graph g2(5); 
    g2.addEdge(0, 1); 
    g2.addEdge(0, 2); 
    g2.addEdge(1, 2); 
    g2.addEdge(1, 4); 
    g2.addEdge(2, 4); 
    g2.addEdge(4, 3); 
    cout << "\nColoring of graph 2 \n"; 
    g2.greedyColoring(); 
	return 0;
}