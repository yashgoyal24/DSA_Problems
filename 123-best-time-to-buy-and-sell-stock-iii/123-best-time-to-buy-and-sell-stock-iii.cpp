class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
         int n=prices.size();
        int count=3;  // atmost 2 transactions, so 0,1 and 2 are possible number of transactions
        int dp[n+1][2][count]; // 3rd dimension represents count

        // base case when index==n
        
        dp[n][0][0]=0;dp[n][0][1]=0;dp[n][0][2]=0;
        dp[n][1][0]=0;dp[n][1][1]=0;dp[n][1][2]=0;
        
        // another base case when count==0, we need to return 0, since we have exhausted our limit
        
        for(int index=0;index<=n-1;index++){
            for(int buy=0;buy<=1;buy++){
                dp[index][buy][0]=0;
            }
            
        }
        
        for(int index=n-1;index>=0;index--){
            
            for(int buy=0;buy<2;buy++){
                
                for(int count=1;count<=2;count++){
                
                if(buy==0){
                    
                    // no buy, only sell
                    
                    dp[index][buy][count] = max(prices[index]+dp[index+1][1][count-1], dp[index+1][0][count]);
                    
                    
                }
                else{
                    
                    // can buy stock
                    
                    dp[index][buy][count]=max(-prices[index]+dp[index+1][0][count], dp[index+1][1][count]);
                    
                }
                
            }
            
            
        }
        }
        
        return dp[0][1][2];
        
        
        
    }
};