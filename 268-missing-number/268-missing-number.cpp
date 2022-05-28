class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        
        int res1=0;
        int res2=0;
        for(int i=0;i<nums.size();i++){
            res1=res1^nums[i];
        }
        for(int i=0;i<=nums.size();i++)
            res2=res2^i;
        
        //xor both the lists
        
        int final_result=res1^res2;
        
        return final_result;
    }
};