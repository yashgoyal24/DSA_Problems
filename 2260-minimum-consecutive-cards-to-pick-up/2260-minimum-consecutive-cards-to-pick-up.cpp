class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        // use map to store element and its index value
        
        map<int,int> mp;
        
        int mini=INT_MAX;
        for(int i=0;i<cards.size();i++){
            
            if(mp.find(cards[i])==mp.end()){ // element not found
              
                mp[cards[i]]=i;
    
            }
            else{ // element found in map
    
                mini=min(mini, (i-mp[cards[i]]+1));
                mp[cards[i]]=i;
            }
            
        }
        
        if(mini!=INT_MAX)
        return mini;
        else
            return -1;
    }
};