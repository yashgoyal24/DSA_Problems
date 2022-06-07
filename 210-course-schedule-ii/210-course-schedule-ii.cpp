class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // to return the topological ordering if possible, else return an empty vector
        
         vector<vector<int>> adj(numCourses);  // adjacency list
        
        vector<int> schedule; // to store final schedule (topological sort)
        
        for(auto it:prerequisites){
            
            adj[it[1]].push_back(it[0]);
            
        }
        
        // now create an array of indegree
        
        vector<int> indeg(numCourses);
        
        for(int i=0;i<adj.size();i++){
            
            for(int j=0;j<adj[i].size();j++){
                indeg[adj[i][j]]++;
            }
            
        }
        
        // create a queue for bfs traversal
        
        queue<int> q;
        
        // push nodes with indegree 0
        
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0)
            q.push(i);
        }
        
        
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            schedule.push_back(node);
            for(auto it:adj[node]){
                
                // traversing neighbours of node
                
                indeg[it]--;
                if(indeg[it]==0)  // since indegree is now 0, push in the queue
                    q.push(it);
                
            }
            
        }
        
        if(schedule.size()==numCourses)
            return schedule;
        return {};
        
    }
};