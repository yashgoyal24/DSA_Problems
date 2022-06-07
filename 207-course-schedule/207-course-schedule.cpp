class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // if no cycle in the directed graph, then we can obtain a topological ordering
        // so, this problem simply boils down to return false if cycle exists, else return true
        
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
            return true;
        return false;
        
    }
};