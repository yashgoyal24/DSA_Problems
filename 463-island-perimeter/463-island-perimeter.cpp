class Solution {
public:
int perimeter=0;
    int islandPerimeter(vector<vector<int>>& grid) {
        
            perimeter=0;
        
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]==1){
                    // call dfs 
                    DFS(grid, i, j);
                    break;
                }
                
            }
        }
        
        return perimeter;
    }
    
    void DFS(vector<vector<int>>& grid,int i,int j){
        
          if(i<0 || j<0 || j>=grid[0].size() || i>=grid.size() || grid[i][j]==0){
              
              // index out of bounds and value 0 
              
              perimeter++;
              return;
              
          }
            if(grid[i][j]==-1)
                return; // visited
            // 1 ko 0 banao, in short make it visited so that ispe vaapis naa aaye
            
            grid[i][j]=-1;
            
            // make 4 calls now
        
        
          
            DFS(grid,i,j+1); // right
            DFS(grid,i,j-1); // left
            DFS(grid,i-1,j); // up
            DFS(grid,i+1,j); // down
            
            
            
    }
        
    
    
    
};