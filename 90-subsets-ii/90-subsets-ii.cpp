class Solution {
public:
    
vector<vector<int>> result;
vector<int> ds;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        Func(nums,0);
        
        // remove duplicates from result
        
        set<vector<int>> s;
        
        for(int i=0;i<result.size();i++){
            s.insert(result[i]);
        }
        
        vector<vector<int>> final;
        
        for(auto it:s){
            final.push_back(it);
        }
        
        
        return final;
    }
    
void Func(vector<int> &nums, int idx){
    
    
    if(idx>=nums.size()){
        result.push_back(ds);
        return;
    }
    
    // pick
    
    ds.push_back(nums[idx]);
    Func(nums,idx+1);
    
    // don't pick
    
    ds.pop_back();
    Func(nums, idx+1);
    
}
};