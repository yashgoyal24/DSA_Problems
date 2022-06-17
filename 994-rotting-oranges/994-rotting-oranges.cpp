class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // the problem is related to bfs
        
        // in the queue, we will push the co-ordinates of rotten oranges initially
        
        queue<pair<int,int>> q;
        int total_oranges=0;
        int fresh_oranges=0;
        int rotten_oranges=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]==2){
                    // rotten hai
                    total_oranges++;
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    //orange is fresh
                    total_oranges++;
                    fresh_oranges++;
                }
                
            }
        }
        
        if(fresh_oranges==0){
            // fresh orange hai hi nahi, to chhod do aise hi
            return 0;
        }
        
        int minutes=-1;
        
        while(!q.empty()){
            
            minutes++;
            int n=q.size();
            rotten_oranges+=n;
            for(int k=0;k<n;k++){
                
            // do for all nodes of the q, since they are at the same level    
                
            int i=q.front().first;
            int j=q.front().second;
            grid[i][j]=0; // markes as visited
            q.pop();
             
            // move in all 4 directions
             if(j-1>=0 && grid[i][j-1]==1)   //left
             {
                 grid[i][j-1]=2;
                q.push({i,j-1});
             }
             if(j+1<grid[0].size() && grid[i][j+1]==1)  //right
             {
                  grid[i][j+1]=2;
                q.push({i,j+1});
             }
            if(i-1>=0 && grid[i-1][j]==1) //up 
            {
                 grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(i+1<grid.size() && grid[i+1][j]==1) //down
               {
                grid[i+1][j]=2;
                q.push({i+1,j});
               }
            
            }
            
            
            
            
            
        }
        
      if(total_oranges!=rotten_oranges)
          return -1;
    else return minutes;
        
        
    }
};