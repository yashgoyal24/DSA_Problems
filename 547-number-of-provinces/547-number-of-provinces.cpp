class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // problem is to find the number of connected components in a graph
        
        
        vector<int> visited(isConnected.size());
        int counter=0;
        
        for(int i=0;i<isConnected.size();i++){
            
            // this loop that traversal runs for all components
            
            if(visited[i]==0){
                counter++;
                BFS(isConnected,i,visited);
                
            }
            
        }
        
       return counter; 
    }
    
    void BFS(vector<vector<int>>& isConnected,int node,vector<int>& visited){
        
        queue<int> q;
        q.push(node);
        visited[node]=1; // marked as visited
        
        while(!q.empty()){
            
            int val=q.front();
            q.pop();
            
            for(int i=0;i<isConnected.size();i++){
                
                if(isConnected[val][i]==1 && visited[i]==0) { // neighbour is connected and not visited
                    
                    q.push(i);
                    visited[i]=1;
                    
                }
                
            }
            
            
        }
        
        
        
    }
};