// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    
    // PRIMS ALGORITHM
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
            // key, mst and parent array are needed
            
            int result=0;
            vector<int> key(V,INT_MAX);
            vector<int> mst(V,0); // initially all are false
            
            key[0]=0; // source
          //  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
         //   q.push({0,0}); // distance and respective node
            for(int i=0;i<V-1;i++){
                
                // choose minimum among the keys
                
                int mini=INT_MAX;
                int u;
                for(int i=0;i<V;i++){
                    if(mst[i]==0 && key[i]<mini){
                        mini=key[i];
                        u=i;
                    }
                }
                
               
                mst[u]=1; // taken in mst
                
                // now will relax neighbours, update keys
                
                for(auto it:adj[u]){
                    
                    if(mst[it[0]]==0 && it[1]<key[it[0]]){
                        
                        // if current edge wt less than key value, then update
                        
                        key[it[0]]=it[1];
                        
                    }
                    
                }
                
                
                
            }
            for(int i=0;i<V;i++){
                result+=key[i];
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