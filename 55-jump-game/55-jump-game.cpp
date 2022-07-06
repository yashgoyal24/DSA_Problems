class Solution {
public:
    
    bool F(vector<int>&nums,int index, int n,vector<int>&dp){
        
        if(index>=n-1){
            return true;
        }
        if(dp[index]!=-1)
            return dp[index];
        for(int i=1;i<=nums[index];i++){
            if(F(nums,index+i,n,dp)){
                return dp[index]=true;
            }
        }
        
        return dp[index]=false;
        
        
        
    } 

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int n=nums.size();
        return F(nums, 0, n, dp);
    }
};