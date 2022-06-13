class Solution {
public:
int dp[200][200];
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        
        
        memset(dp,-1,sizeof(dp));
        return F(triangle,0, 0);
    }
    
    int F(vector<vector<int>>& triangle, int i, int j){
        
        // F(i,j) = min cost path from (i,j) till any cell on the last row (destination)
        
        if(i==triangle.size()-1){ // reached last row
            
            return triangle[i][j];
            
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int bottom=F(triangle,i+1,j)+triangle[i][j];
        int diag=F(triangle,i+1,j+1)+triangle[i][j];
        return dp[i][j]=min(bottom, diag);
            
        
        
        
    }
};