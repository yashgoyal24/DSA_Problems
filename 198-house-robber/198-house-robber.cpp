class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        int dp[n+1]; // dp[i] denotes max cost from 1 index till index i
        
        dp[0]=0;
        dp[1]=nums[0]; // base case for 1st item
        
        for(int i=2;i<=n;i++){
            
            int pick=nums[i-1]+dp[i-2];
            int not_pick=dp[i-1];
            
            dp[i]=max(pick,not_pick);
            
        }
        
        
        return dp[n];
        
    }
};