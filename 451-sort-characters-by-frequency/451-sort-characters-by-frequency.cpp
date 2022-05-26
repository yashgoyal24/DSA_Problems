class Solution {
public:
    string frequencySort(string s) {
        
           string result;
        
        //create a map storing count and respective number
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
                mp[s[i]]+=1;            
        }
        
        //create a maxheap, to pop off lower frequency elements
        
        priority_queue<pair<int,char>> maxheap;
        
        for(auto i=mp.begin();i!=mp.end();i++){
            
            maxheap.push({i->second,i->first});
           
        }
        
        while(maxheap.size()>0){
            
            int frequency=0;
            frequency=maxheap.top().first;
            for(int i=0;i<frequency;i++){
                 result.push_back(maxheap.top().second);
                
              //  cout<<maxheap.top().second<<"\n";
            }
           
            maxheap.pop();
            
        }
       
        return result;
    }
};