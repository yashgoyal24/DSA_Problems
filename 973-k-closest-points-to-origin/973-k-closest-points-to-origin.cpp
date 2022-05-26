class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        
        //Create a max heap
        
    
        priority_queue<pair<long,pair<int,int>>> maxheap;
        
        for(int i=0;i<points.size();++i){
            
            
           long distance=points[i][0]*points[i][0] + points[i][1]*points[i][1];
            
                
                
            maxheap.push({distance,{points[i][0],points[i][1]}});
            
            if(maxheap.size()>k){
                
                maxheap.pop();
            
        }
        
        }
        
        //Code to add points to resultant 2d array
        
        while(maxheap.size()>0){
            
            pair<int,int> point=maxheap.top().second;
            
            vector<int> vtp;
            
            vtp.push_back(point.first);
            vtp.push_back(point.second);
            result.push_back(vtp);
            
            maxheap.pop();
        }
        
        
        
        
        
        return result;
    }
};