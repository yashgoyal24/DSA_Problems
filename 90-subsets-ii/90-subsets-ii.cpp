class Solution {
public:
    
    void F(vector<int>&nums,vector<int> &ds, vector<vector<int>> &result,int index,int n){
        
        if(index>=n){
            result.push_back(ds);
            return;
        }
        //pick
        
        ds.push_back(nums[index]);
        F(nums,ds,result,index+1,n);
        //not pick
        ds.pop_back();
        F(nums,ds,result,index+1,n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n=nums.size();
        vector<int> ds;
        F(nums,ds,result,0,n);
        // remove duplicates from result
        vector<vector<int>> answer;
        set<vector<int>> s;
        for(auto it:result){
            s.insert(it);
        }
        for(auto it:s){
            answer.push_back(it);
        }
        
        return answer;
    }
};