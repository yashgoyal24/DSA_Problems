class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // below method is O(n) TC and SC and uses hashing
        vector<int> result;
        map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        
        for(auto it:mp){
            if(it.second!=1)
                result.push_back(it.first);
            
        }
     return result;   
    }
};