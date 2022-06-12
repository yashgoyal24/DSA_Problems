class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n=nums.size(); // numbers are in range[1,n]
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            mp[i]=1;
        }
        
        for(auto it:nums){
            mp.erase(it);
        }
        
        for(auto it:mp){
            result.push_back(it.first);
        }
        return result;
    }
};