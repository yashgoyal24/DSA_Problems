class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> result;
        
        //create a map storing count and respective number
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
                mp[nums[i]]+=1;            
        }
        
        //create a min heap, to pop off lower frequency elements
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        
        for(auto i=mp.begin();i!=mp.end();i++){
            
            minheap.push({i->second,i->first});
            if(minheap.size()>k){
                minheap.pop();
            }
            
        }
        
        while(minheap.size()>0){
            
            result.push_back(minheap.top().second);
            minheap.pop();
            
        }
        
        sort(result.begin(),result.end());
        return result;
        
    }
};