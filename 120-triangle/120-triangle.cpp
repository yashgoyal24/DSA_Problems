class Solution {
public:
int dp[200][200];
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        
        
        // dp solution
        
        int n=triangle.size();
        
        // fill for base case
        
        for(int j=0;j<triangle[n-1].size();j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        
        // now do for rest of the cases
        
        for(int i=n-2;i>=0;i--){
            
            for(int j=0;j<triangle[i].size();j++){
                
                // copy recurrence as it is
                
        int bottom=dp[i+1][j]+triangle[i][j];
        int diag=dp[i+1][j+1]+triangle[i][j];
        dp[i][j]=min(bottom, diag);
                
                
            }
            
        }
        return dp[0][0];
        
        
        
       
       // return F(triangle,0, 0);
    }
    
 /*   int F(vector<vector<int>>& triangle, int i, int j){   // Memoization solution
        
        // F(i,j) = min cost path from (i,j) till any cell on the last row (destination)
        
        if(i==triangle.size()-1){ // reached last row
            
            return triangle[i][j];
            
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int bottom=F(triangle,i+1,j)+triangle[i][j];
        int diag=F(triangle,i+1,j+1)+triangle[i][j];
        return dp[i][j]=min(bottom, diag);
            
        
        
        
    }*/
};