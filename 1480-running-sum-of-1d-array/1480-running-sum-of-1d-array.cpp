class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> result;
        int sum=0;
        
        for(auto it:nums){
            
            sum+=it;
            result.push_back(sum);
            
        }
        return result;
    }
};