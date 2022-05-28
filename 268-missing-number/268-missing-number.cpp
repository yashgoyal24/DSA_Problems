class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        
     
        int res2=0;
       
        for(int i=0;i<=nums.size();i++)
            res2=res2^i;
        
         for(int i=0;i<nums.size();i++){
            res2=res2^nums[i];
        }
        //xor both the lists
        
       
        
        return res2;
    }
};