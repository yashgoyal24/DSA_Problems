class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        int dp[n+1][2]; 

        // base case
        
        dp[n][0]=0;dp[n][1]=0;
        
        for(int index=n-1;index>=0;index--){
            
            for(int buy=0;buy<2;buy++){
                
                if(buy==0){
                    
                    // no buy, only sell
                    
                    dp[index][buy] = max(prices[index]+dp[index+1][1]-fee, dp[index+1][0]);
                    
                    
                }
                else{
                    
                    // can buy stock
                    
                    dp[index][buy]=max(-prices[index]+dp[index+1][0], dp[index+1][1]);
                    
                }
                
            }
            
            
        }
        
        return dp[0][1];
    }
};