class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
         if(nums.size()==1)
            return 0;
        int low=1;
        int high=nums.size()-2; // handle first and last position separately
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                // peak found
                return mid;
                
            }
            else if(nums[mid+1]>nums[mid]){
                // move to right side
                low=mid+1;
            }
            else{
                // move to left side
                high=mid-1;
            }
            
        }
        
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        
        
        
        
        return -1;
    }
};