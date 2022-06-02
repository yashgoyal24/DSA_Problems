class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size(),-1);
        
        // since graph may be unconnected, run the below loop
        
        
        for(int i=0;i<graph.size();i++){
            
            if(color[i]==-1){  // node not visited
    
               if(!isBP(i,graph,color))
                   return false;
                   
            }
          
        }
        
        return true;
    }
    
   bool isBP(int node, vector<vector<int>>& graph,vector<int> &color){
       
       queue<int> q;
       q.push(node);
       color[node]=0;   // assign color 0 to node 0
       
       while(!q.empty()){
           
           int val=q.front();
           q.pop();
           
          for(auto it:graph[val]){
              // "it" is neighbours of val node
              
              if(color[it]==-1){
                  // no color assigned, so assign opposite color to node
                  if(color[val]==1)
                      color[it]=0;
                  else
                      color[it]=1;  
                  
                 q.push(it);
              }
              else{ // color already assigned to neighbour, check if opposite
                  
                  if(color[it]==color[val])
                      return false;
                  
                  
              }
              
          }
           
       }
       return true;
   } 
    
};