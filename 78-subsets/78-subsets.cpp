class Solution {
public:
vector<vector<int>> result;
vector<int> ds;
    vector<vector<int>> subsets(vector<int>& nums) {
        Func(nums,0);
        
        return result;
    }
    
    void Func(vector<int>& nums,int idx){
        
        if(idx>=nums.size()){
            result.push_back(ds);
            return;
        }
        
        // pick
        
        ds.push_back(nums[idx]);
        Func(nums,idx+1);
        
        // pop from ds as don't pick case
        
        ds.pop_back();
        Func(nums,idx+1);
        
        
        
        
    }
};