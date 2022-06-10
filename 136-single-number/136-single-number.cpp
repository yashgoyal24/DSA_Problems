class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int var=0;
        
        for(int i=0;i<nums.size();i++){
            var=var^nums[i];
        }
        
        return var;
    }
};