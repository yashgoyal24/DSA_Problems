class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        // dfs use kar sakte hai
        
        int counter=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]=='1'){
                    // dfs chala do for all components
                    counter++;
                    DFS(grid, i, j);
                }
                
            }
        }
        
        
        
        
        
        return counter;
    }
    
    void DFS(vector<vector<char>>& grid,int i,int j){
        
        // check for overflow for i and j
        
        if(i>=0 && j>=0 && j<grid[0].size() && i<grid.size() && grid[i][j]=='1'){
            
            // 1 ko 0 banao, in short make it visited so that ispe vaapis naa aaye
            
            grid[i][j]='0';
            
            // make 4 calls now
            
            DFS(grid,i,j+1); // right
            DFS(grid,i,j-1); // left
            DFS(grid,i-1,j); // up
            DFS(grid,i+1,j); // down
            
            
            
            
        }
        
        
    }
};