#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Edge
{
	int src;
	int dest;
	int wei;
};

bool cmp(Edge const &a,Edge const &b)
{
	return a.wei<b.wei;
}

class Graph
{
  private:
  	int V;
  	int E;
  	int *unionArray;
  public:
  	Edge *arr;
  	Graph(int a,int b)
  	{
  		V=a;
  		E=b;
  		arr=new Edge [E];
  		unionArray=new int [V];
  		for(int i=0;i<V;i++) unionArray[i]=-1;
  	}
    
    int getRoot(int u)
    {
    	while(unionArray[u]>=0)
    	{
          u=unionArray[u];
    	}

    	return u;
    }

    bool joinBoth(int u,int v)
    {
    	int x=getRoot(u);
    	int y=getRoot(v);
        
        if(x==y) return false;

    	if(unionArray[x]<unionArray[y])
    	{
    		unionArray[x]+=unionArray[y];
    		unionArray[y]=x;
    	}else
    	{
    		unionArray[y]+=unionArray[x];
    		unionArray[x]=y;
    	}
    	return true;
    }

  	void printKruskelMST()
  	{
  		sort(arr,arr+E,cmp);
		ll MST=0;

  		for(int i=0;i<E;i++)
  		{
  			if(joinBoth(arr[i].src,arr[i].dest))
  			{
              MST+=arr[i].wei;
  			}
  		}

  		cout<<MST<<"\n";	
  	}  	
};
int main()
{
	int n,m;
	cin>>n>>m;
    
    Graph g(n,m);
    for(int i=0;i<m;i++)
    {
    	cin>>g.arr[i].src>>g.arr[i].dest>>g.arr[i].wei;
    }

    g.printKruskelMST();
	return 0;
}