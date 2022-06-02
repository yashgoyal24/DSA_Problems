// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> dfs;
        
        vector<int> visited(V,0);   // visited array
        
        
       DFS(0, visited, adj, dfs);
        
        return dfs;
    }
    
    void DFS(int node, vector<int> &visited, vector<int> adj[],vector<int> &dfs){
        
        visited[node]=1;
        dfs.push_back(node);
        
        for(auto it: adj[node]){
            
            if(visited[it]==0){ // node not visited
            
                DFS(it,visited,adj,dfs);

            }
        }
        
        
        
    }
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends