class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         
        int sum=0;
        int max_sum=INT_MIN;      //since atleast 1 element is present
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
            max_sum=max(max_sum,sum);
            
            if(sum<0)
            sum=0;     //since negative number will decrease the current sum, so start with a new window
            
        }
        
        
        
        return max_sum;
    }
};