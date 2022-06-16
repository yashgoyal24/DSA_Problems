class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        // problem is to find number of components
        // if number of components=1, return true
        // else return false
        
        vector<int> visited(rooms.size());
        BFS(rooms,0,visited); 
        
        // now check visited matrix, if any entry is 0, return false else return true
                
        for(auto it:visited){
            if(it==0){
                return false;
            }
        }
            
        
        
      
       return true; 
        
        
    }
    
     void BFS(vector<vector<int>>& rooms,int node,vector<int>& visited){
        
        queue<int> q;
        q.push(node);
        visited[node]=1; // marked as visited
        
        while(!q.empty()){
            
            int val=q.front();
            q.pop();
            
            for(auto it:rooms[val]){
                
                if(visited[it]==0) { // neighbour is connected and not visited
                    
                    q.push(it);
                    visited[it]=1;
                    
                }
                
            }
            
            
        }
        
        
        
    }
};