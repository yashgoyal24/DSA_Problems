class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> result;
        sort(arr.begin(),arr.end());
        map<int,vector<int>> mp; // number of 1s and value is integers
        for(int i=0;i<arr.size();i++){
            
            int temp_counter=0;
            int n1=arr[i];
            while(n1>0){
                temp_counter++;
                
                n1=n1&(n1-1);
            }
           mp[temp_counter].push_back(arr[i]);
            
        }
        
        for(auto it:mp){
            
            vector<int> temp=it.second;
            for(auto it1:temp){
                result.push_back(it1);
            }
            
        }
        
        
        return result;
        
        
        
        
    }
};