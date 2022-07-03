class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        
        return F(matrix,dp,m-1,n-1);
    }
    
    int F(vector<vector<int>> &matrix,vector<vector<int>>&dp,int i,int j){
        if(i==0&&j==0){
            return 1; // reached destination
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=0,up=0;
        left=F(matrix,dp,i,j-1);        
        up=F(matrix,dp,i-1,j);
        return dp[i][j]=left+up;
    }
};