class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        //create a map which stores element and its index
        
        map<int,int> mp;
        
        vector<int> result; //to store pair of indices
        
        for(int i=0;i<nums.size();i++){
            
            //check if (target-nums[i]) present in map
            
            if(mp.find(target-nums[i]) != mp.end()){
                result.push_back(mp[target-nums[i]]);
                result.push_back(i);
                break;
            }
    
            //push element in the end
            
            mp[nums[i]]=i;
        }
        
        return result;
    }
};