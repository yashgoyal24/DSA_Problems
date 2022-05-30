class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        
        //sort according to first value;
        
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();i++){
            
            if(result.size()==0 || intervals[i][0] > result.back()[1]){
                
                //form a new entry and push into data structure
                
                result.push_back({intervals[i][0],intervals[i][1]});
                
            }
            else{
                
                //merge with last entry in the data structure
                
               result.back()[1]=max(intervals[i][1],result.back()[1]);
                
            }
            
        }
    
        return result;
    }
};