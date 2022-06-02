// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> bfs; // to store final result
        
        vector<int> visited(V,0);  // visited array, initially all 0s
        
        queue<int> q; // to store nodes in a queue
        
        q.push(0);
        visited[0]=1;
        while(!q.empty()){   // iterate till queue non-empty
            
            int element=q.front();
          // mark vertex as visited
              bfs.push_back(element);
            q.pop();
            
            for(auto it:adj[element]){
                if(visited[it]==0){
                    q.push(it);
                       visited[it]=1; 
                }
            }
            
          
        }
            
         
        
        
        return bfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends