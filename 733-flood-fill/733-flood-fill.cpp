class Solution {
public:
    
    void fillDFS(vector<vector<int>>& image, int i, int j, int color,int n,int m,int old_color){
        
        
        if(i>=0 and j>=0 and i<n and j<m and image[i][j]==old_color){
            
            image[i][j]=color;
        
            fillDFS(image,i+1,j,color,n,m,old_color);
            fillDFS(image,i,j+1,color,n,m,old_color);
            fillDFS(image,i,j-1,color,n,m,old_color);
            fillDFS(image,i-1,j,color,n,m,old_color);
              
        }
      
        
        
        
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int i=sr;
        int j=sc;
        int n=image.size();
        int m=image[0].size();
        int old_color=image[i][j];
        if(old_color==color)
            return image;
        fillDFS(image,i,j,color,n,m,old_color);
        
        
        
        return image;
    }
};