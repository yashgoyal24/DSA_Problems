class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int ans=0;
        int slow=nums[0];
        int fast=nums[0];
        do{
           slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        
        // now put fast at nums[0] and slow at same pos
        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
    }
};