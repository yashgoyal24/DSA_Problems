class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // scan from left and choose index i where nums[i]<nums[i+1]
        
        int idx1=-1,idx2=-1;
        for(int i=nums.size()-2;i>=0;i--)
        { 
            if(nums[i]<nums[i+1]){
                idx1=i;
            break;}
         }
        
        // scan from left and choose index idx2 where nums[idx2]>nums[idx1]
        
        if(idx1==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[idx1]){
                idx2=i;
                break;
            }
            
        }
        
        // if idx1==-1, means sequence is decreasing so idx1 not found, simply reverse nums
        
        
      
        // swap elements at idx1 and idx2
        
        swap(nums[idx1], nums[idx2]);
        
        // reverse from idx1+1 till end
        
        reverse(nums.begin()+idx1+1,nums.end());
        }
    }
};