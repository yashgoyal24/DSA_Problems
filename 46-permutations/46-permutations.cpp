class Solution {
public:
    
    void generatePermutations(vector<int>&nums,vector<vector<int>> &result,vector<int> &visited,vector<int>&ds){
        
        
        
        if(ds.size()==nums.size()){
            cout<<"hello";
            result.push_back(ds);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++){
            
            if(visited[i]==0){
                ds.push_back(nums[i]);
                visited[i]=1;
                generatePermutations(nums,result,visited,ds);
                ds.pop_back();
                visited[i]=0;
            }
            
            
            
        }
        
        
        
        
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        vector<int> visited(nums.size(),0);
        generatePermutations(nums,result,visited,ds);
        
        
        
        return result;
    }
};