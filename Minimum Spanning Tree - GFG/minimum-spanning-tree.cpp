// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// KRUSKAL ALGORITHM

class Solution
{
	public:
	
	
		struct node{
	    int weight;
	    int u;
	    int v;
	    node(int wt,int u1,int v1){
	        weight=wt;
	        u=u1;
	        v=v1;
	    }
	};
	
	
	  vector<node> edges;
	  int parent[1000];
      int rank[1000];
      

	
	static bool cmp(node n1,node n2){
	    return n1.weight<n2.weight; // increasing order of weights
	}
	
	int findParent(int x){
	    if(parent[x]==x){
	        return x;
	    }
	    return parent[x]=findParent(parent[x]); // path compression
	}
	
	void unionn(int x,int y){
	    x=findParent(x);
	    y=findParent(y);
	    if(rank[x]<rank[y]){
	        parent[x]=y;
	    }
	    else if(rank[y]<rank[x]){
	        parent[y]=x;
	    }
	    else // ranks are equal
	    {
	        parent[x]=y;
	        rank[y]++;
	    }
	    
	    
	}
	
	
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int result=0;
      
        for(int i=0;i<V;i++){
            
            for(auto it:adj[i]){
                edges.push_back(node(it[1],i,it[0]));
            }
            
        }
        
        // sort in increasing order of weights
        
        sort(edges.begin(),edges.end(),cmp);
        
         // first do make set operation
        
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        // start picking all the edges now
        for(int i=0;i<edges.size();i++){
            
            if(findParent(edges[i].u)!=findParent(edges[i].v)){
                
                // different component, so merge
                
                unionn(edges[i].u,edges[i].v);
                result+=edges[i].weight;
                
                
                
            }
            else{
                // same component, so ignore
                continue;
            }
            
        }
        
        
        return result;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends