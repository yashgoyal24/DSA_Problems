class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        // need to perform dfs in this question
       
        int current_color=image[sr][sc];
        if(current_color==color)
            return image;
        DFS(image,sr,sc,current_color,color);
        
        
        return image;
        
        }
        
        
        
    

void DFS(vector<vector<int>>& grid,int i,int j,int current_color, int color){
        
        // check for overflow for i and j
        
        if(i>=0 && j>=0 && j<grid[0].size() && i<grid.size() && grid[i][j]==current_color){
            
            // 1 ko 0 banao, in short make it visited so that ispe vaapis naa aaye
            
            grid[i][j]=color;
            
            // make 4 calls now
            
            DFS(grid,i,j+1,current_color,color); // right
            DFS(grid,i,j-1,current_color,color); // left
            DFS(grid,i-1,j,current_color,color); // up
            DFS(grid,i+1,j,current_color,color); // down
            
            
            
            
        }
        
        
    }
};