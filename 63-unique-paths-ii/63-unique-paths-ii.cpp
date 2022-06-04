class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int dp[m][n];
        dp[0][0]=1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int left,up;
                if(i==0 && j==0)
                    continue;
                
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                     if(j>=1)
                    left=dp[i][j-1];
                else
                    left=0;
                if(i>=1)
                    up=dp[i-1][j];
                else
                    up=0;
                dp[i][j]=left+up; // all possible ways ka sum
                    
                }
                
            }
        }
        return dp[m-1][n-1];
        
    }
};