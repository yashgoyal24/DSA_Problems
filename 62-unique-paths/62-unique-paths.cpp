class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // using dp on grids
        
        int dp[m][n];
       // dp[0][0]=1;
       
        int left=0,up=0;
        for(int i=0;i<m;i++){
            
            
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) {
                  // first cell base case
                dp[i][j]=1;
                    continue;
                    cout<<i<<j<<dp[0][0];
                } 
                if(j>=1)
                    left=dp[i][j-1];
                else
                    left=0;
                if(i>=1)
                    up=dp[i-1][j];
                else
                    up=0;
                dp[i][j]=left+up; // all possible ways ka sum
                
               // cout<<dp[0][0];
            }
        }
        
        
        return dp[m-1][n-1];
    }
};