class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // using map
        
     unordered_map<int,int> mp; // to store number and its count
        
        for(auto it:nums){
            mp[it]++;
        }
        
        for(auto it:mp){
            
            if(it.second>=2){
                return true;
            }
            
        }
    
    return false;
}
};