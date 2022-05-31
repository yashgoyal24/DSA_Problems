class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
       int counter=0;
        
        //map to store prefix sum and its index
        
        map<int,int> mp;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
          
            
            if(sum==k){
                counter++;
             
              
            }
            
            if(mp.find(sum-k)!=mp.end()){ 
                //sum found
                counter+=mp[sum-k];
               
               
            }
            
            mp[sum]++;

              
        }
    
    return counter;
    
        
        
    }
};