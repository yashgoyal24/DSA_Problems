class Solution {
public:
    int F(vector<int>&nums,int n,vector<int>&dp,int index,int mini){
        
        if(index>=n-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=1;i<=nums[index];i++){
            mini=min(mini,1+F(nums,n,dp,index+i,mini));
        }
        return dp[index]=mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int n=nums.size();
        int mini=1e9;
        return F(nums,n,dp,0,mini);
    }
};