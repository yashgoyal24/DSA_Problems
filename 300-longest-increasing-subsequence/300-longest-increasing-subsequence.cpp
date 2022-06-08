class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        return LIS(nums, n, 0, -1);
        
    }
    
   /* int LIS(vector<int> &nums,int n, int curr, int prev){
        
        if(curr==n)
            return 0;
        int len2=0;
        int len1=LIS(nums, n, curr+1, prev); // not pick
        if(prev==-1 || nums[curr]>nums[prev])  // pick case
            len2=1+LIS(nums,n,curr+1,curr);
      
        return max(len1, len2);
        
    }*/
    
    int LIS(vector<int> &nums,int n, int curr, int prev){
        
        int dp[n+1][n+1];  // curr and prev
    for(int i=0;i<=n;i++){
        dp[n][i]=0;  // base case
    }
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                
           int len2=0;     
        int len1=dp[i+1][j+1]; // not pick
        if(j==-1 || nums[i]>nums[j])  // pick case
            len2=1+dp[i+1][i+1];
      
        dp[i][j+1]=max(len1, len2);
            }
        }
        return dp[0][0];
    }
};