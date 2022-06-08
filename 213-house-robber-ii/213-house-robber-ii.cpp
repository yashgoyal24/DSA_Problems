class Solution {
public:
    int rob(vector<int>& nums) {
        
        // first take cost ignoring first element, another ignoring last element and then take max of both
        
        if(nums.size()==1)
            return nums[0];
        
        vector<int> nums_copy=nums;
        nums_copy.erase(nums_copy.begin());
        int cost1=robHelper(nums_copy);
        nums.pop_back();
        int cost2=robHelper(nums);
        
        return max(cost1, cost2);
        
    }
    
     int robHelper(vector<int> nums) {
        
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