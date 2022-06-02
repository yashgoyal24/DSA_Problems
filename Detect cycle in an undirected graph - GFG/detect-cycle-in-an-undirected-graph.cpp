// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
         vector<int> visited(V,0); // visited array 
        queue<pair<int,int>> q;
        
        for(int i=0;i<V;i++){
            
            if(visited[i]==0){  // call function
                if(Function(i, q, visited, adj)){
                    return true;
                }
            }
        }
        return false;
       
    }
    
    bool Function(int &val, queue<pair<int,int>> &q, vector<int> &visited, vector<int> adj[]){
        
        
         // use BFS to detect cycle
        
        // push node and its parent in the queue
        
       
    
        q.push({val,-1});
        visited[val]=1;
        while(!q.empty()){
            
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            // traverse to neighbours of node
            
            for(auto it:adj[node]){
                
                if(visited[it]==0){  // neighbour unvisited
                    q.push({it,node});
                    visited[it]=1;
                }
                else{  // neighbour already visited
                    
                    if(it!=parent)  // adjacent not equal to parent, so cycle exists
                    return true;
                }
                
            }
            
            
        }
       return false; 
        
        
        
        
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends