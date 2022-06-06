class Solution {
public:
vector<vector<int>> result;
vector<int> ds;
map<int,int> mp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         for(int i=0;i<nums.size();i++){
                mp[i]=0;
            }
        sort(nums.begin(),nums.end());
        
        Func(nums);
           // insert result vectors in a set
        
        set<vector<int>> s;
        for(auto it:result)
            s.insert(it);
        
        
        vector<vector<int>> final;
        for(auto it:s)
            final.push_back(it);
            return final;
        
    }
    void Func(vector<int>& nums){
        
        if(ds.size()==nums.size()){
            // add this vector to solution
            result.push_back(ds);
            return;
        }
        
        // map stores index number and wheter it is taken or not
        
        // add to ds
        
        for(int i=0;i<nums.size();i++){
            
            if( mp[i]==0 ){
                // element not found
                ds.push_back(nums[i]);
                mp[i]=1;
                Func(nums); // to pick next set of elements
                mp[i]=0;
                ds.pop_back();
               
            }
        
            
        }
        
        
        
        // remove from ds and trace back
        
        
    }
};