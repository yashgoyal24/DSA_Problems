class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int val1=F(cost,n,0,dp);
        int val2=F(cost,n,1,dp);
        return min(val1,val2);
        
    }
    
    // F(index) - min cost to reach from index till end
    
    int F(vector<int>&cost, int n, int index,vector<int>&dp){
        
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
            
        }
        return dp[index]=min(cost[index]+F(cost,n,index+1,dp),
                            cost[index]+F(cost,n,index+2,dp));
        
        
    }
};