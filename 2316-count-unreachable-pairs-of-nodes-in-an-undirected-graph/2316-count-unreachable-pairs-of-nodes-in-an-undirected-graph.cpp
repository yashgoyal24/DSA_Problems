class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // apply bfs 
        vector<int> component_nodes;
        vector<int> visited(n,0);
        long long result=0;
      //  vector<vector<int>> adj(n);
        map<int,vector<int>> adj_mp;
        for(auto it:edges){
            
            adj_mp[it[0]].push_back(it[1]);
            adj_mp[it[1]].push_back(it[0]);
            
        }
        int num=n;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                int component_count=bfs(n,adj_mp,i,visited,component_nodes);
                result+=(long long)(component_count)*(num-component_count);
                num=num-component_count;
            }
        }
        
        
        
        
        return result;
    }
    
    int bfs(int n, map<int,vector<int>>& adj,int node,vector<int> &visited,vector<int> &component_nodes){
        int temp_count=0;
        queue<int> q;
        
        q.push(node);
        temp_count++;
        visited[node]=1;
        
        while(!q.empty()){
            
            int n1=q.front();
            q.pop();
          
                
                for(auto it:adj[n1]){
                
                
                // neignbours
                if(visited[it]==0 ){
                    //unvisited
                    temp_count++;
                    q.push(it);
                    visited[it]=1;
                }
                
          
                }
            
        }
     
        return temp_count;        
    }
};