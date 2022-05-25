class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int final_index;
        vector<int> remaining;
        
        for(int i=0;i<capacity.size();i++){
            remaining.push_back(capacity[i]-rocks[i]);
            
        }
        
        //sort the remaining wala array
        
    sort(remaining.begin(),remaining.end());
        
        int count;
        for(int i=0;i<remaining.size();i++){
            
            additionalRocks=additionalRocks-remaining[i];
             if(additionalRocks<0){
                final_index=i;
                return final_index;
            }
            if(i==(remaining.size()-1)){
                return (remaining.size());
            }
           
            
            
        }
        
        return 0;
    
    }
};