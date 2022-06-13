class Solution {
public:
int dp[100][100];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // start from a fixed point in the first row, find the min path sum
        // Do the same for all remaining points from the first row
        // Return the minimum of all these final values
       F(matrix);
    int mini=dp[0][0];
    for(int i=1;i<matrix.size();i++){
        
        mini=min(mini,dp[0][i]);
        
    }  
  
        
      return mini;  
    }
    
    void F(vector<vector<int>>& triangle){
           // dp solution
        
        int n=triangle.size();
        
        // fill for base case
        
      
        // last cell ke kisi bhi element pe aa gaye, to ruk jaayenge
        for(int j=0;j<triangle[n-1].size();j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        
        // now do for rest of the cases
        
        for(int i=n-2;i>=0;i--){
            
            for(int j=0;j<triangle[i].size();j++){
                
                // copy recurrence as it is
        int bottom=1e5,diag_left=1e5,diag_right=1e5;  
        bottom=dp[i+1][j]+triangle[i][j];
        if(j==triangle[i].size()-1){
           diag_right=INT_MAX;
        }
        else
        diag_right=dp[i+1][j+1]+triangle[i][j];
        if(j==0)
            diag_left=INT_MAX;
        else
            diag_left=dp[i+1][j-1]+triangle[i][j];
        dp[i][j]=min(bottom,min(diag_right,diag_left));
                
                
            }
            
        }

    }
};