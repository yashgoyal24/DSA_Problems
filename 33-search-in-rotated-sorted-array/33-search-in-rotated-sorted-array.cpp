class Solution {
public:
    int search(vector<int>& nums, int target) {
        // check for already
        int min_index=fMin(nums);
        cout<<min_index;
        
     int bs1=bSearch(nums, 0, min_index-1,target);
        cout<<bs1;
    int bs2=bSearch(nums, min_index,nums.size()-1,target);
        cout<<bs2;
      if(bs1!=-1)
          return bs1;
        else if(bs2!=-1)
            return bs2;
        else
            return -1;
    }
    
    int bSearch(vector<int> &nums, int low, int high, int target){
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
            cout<<mid;
            if(nums[mid]==target)
                return mid;
            else if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
        
    }
    
    int fMin(vector<int> &nums){
          if(nums.size()==1)
            return 0;
        
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
                
                return mid;  // found the minimum element
                
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