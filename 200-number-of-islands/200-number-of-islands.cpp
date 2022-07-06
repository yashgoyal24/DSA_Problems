class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int n,int m,int i,int j){
        
        
        if(i<0 or j<0 or i>=n or j>=m){
            return;
        }
        if(grid[i][j]=='1'){
            grid[i][j]=0;
        
        
        
       // if(i>=0 and j>=0 and j<m and i<n and grid[i][j]=='1'){
            
          //  grid[i][j]='0';
          
            
        
    
        dfs(grid,n,m,i+1,j);
        dfs(grid,n,m,i,j+1);
        dfs(grid,n,m,i,j-1);
        dfs(grid,n,m,i-1,j);
        }
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        int counter=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,n,m,i,j);
                    counter++;
                }
            }
        }
        
     return counter;   
    }
};