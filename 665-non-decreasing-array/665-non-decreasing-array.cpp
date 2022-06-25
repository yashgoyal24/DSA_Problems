class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            
            // make cases for replacing the elements
            
            
            if(nums[i]>nums[i+1]){
                
                // kisko kisse replace karenge make cases, i=i+1 OR i+1=i
                
                if(i>=1 && nums[i+1]<nums[i-1]){
                    nums[i+1]=nums[i];
                    break;
                    
                }
                else {
                    nums[i]=nums[i+1];
                    break;
                }
                
            
            }
            
        }
        
        // now check if it is non-decreasing
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
};