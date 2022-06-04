class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up=INT_MAX,left=INT_MAX;
                if(i==0 && j==0)
                    continue;
                else{
                    
                    if(j>=1)left=grid[i][j]+dp[i][j-1];  // left path cost
                    if(i>=1)up=grid[i][j]+dp[i-1][j];
                    
                    dp[i][j]=min(left,up);
                    
                }
                
            }
        }
        
        
       return dp[m-1][n-1]; 
    }
};