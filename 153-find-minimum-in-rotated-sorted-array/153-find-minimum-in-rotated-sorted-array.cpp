class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        // minimum element will be less than both of its neighbours
        
        int low=0;
        int n=nums.size();
        int high=n-1;
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            // find both neighbours
            
            int prev=(mid-1+n)%n;  // to check in circular manner
            int next=(mid+1)%n;    // to check in circular manner
            
            if(nums[mid]<nums[prev] && nums[mid]<nums[next]){
                
                return nums[mid];  // found the minimum element
                
            }
            
            else if(nums[high]<=nums[mid]){ // this is sorted part, so go to opposite
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
                
  
                
            }
        
        return -1;
    }
};