class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        
        // same as unbounded knapsack
        
           // using bottom up approach 
        
       if(amount==0)
           return 1;
       
       int dp[coins.size()+1][amount+1];   // n+1, w+1
        
       // base case
       
       for(int i=0;i<=coins.size();i++){
           dp[i][0]=1; // sum as 0, all cases possible
       }
       for(int j=0;j<=amount;j++){
           dp[0][j]=0;
       }
       
      for(int i=1;i<=coins.size();i++){
          
          for(int j=1;j<=amount;j++){
              
              if(coins[i-1]<=j){
                  // include or don't include
                  dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
                  cout<<dp[i][j];
              }
              else{
                  
                  // don't include
                  
                  dp[i][j]=dp[i-1][j];
              }
              
          }
          
      }
       
      return dp[coins.size()][amount] ;
    }
};