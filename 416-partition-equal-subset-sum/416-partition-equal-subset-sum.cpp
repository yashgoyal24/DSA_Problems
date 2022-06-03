class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        // find if a subset with sum = sum(nums)/2 exists
        // if sum(nums)=odd, no partition is possible
        
        int sumNums=0;
        for(auto it:nums){
            sumNums+=it;
        }
        
        if(sumNums%2!=0)
            return false;
        else{
            int s=sumNums/2;
            return subsetSum(nums,s);
        }
            
        
        
        
        
    }
    
    bool subsetSum(vector<int> &nums, int &W){
        
        // use dp approach 
        int N=nums.size();
        int dp[N+1][W+1];
        
        // initialization
        
        for(int i=0;i<N+1;i++){
            dp[i][0]=true;   // for sum=0, all cases valid 
        }
        
        for(int i=1;i<W+1;i++){
            dp[0][i]=false;  // for items 0, none possible except sum 0
        }
        
        // now fill the dp table
        
          for(int i=1;i<N+1;i++){
              for(int j=1;j<W+1;j++){
                  
                  if(nums[i-1]<=j){
                      
                     dp[i][j]= ( dp[i-1][j] || dp[i-1][j-nums[i-1]] ); // not include or include try both the cases
                  }
                  else{
                      dp[i][j] = dp[i-1][j];  // not include item
                  }
                  
              }
          }  
        
       return dp[N][W]; 
    }
};