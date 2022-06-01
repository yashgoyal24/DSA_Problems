class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        if(nums.size()<=2){
            return {};
        }
        
        // atleast 3 elements are present
        
        //sort the nums array first
        
        sort(nums.begin(),nums.end());
        
        int i=0;
        
        while(i<=nums.size()-3){
            vector<int> temp(3);
            int req_sum=0-nums[i];
            
            //apply 2 pointer approach to right portion of the array
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                
                if(nums[start]+nums[end]==req_sum){
                    temp[0]=nums[i];
                    temp[1]=nums[start];
                    temp[2]=nums[end];
                    result.push_back(temp);
                  start++;end--;
                }
                else if(nums[start]+nums[end]<req_sum){
                    start++;
                }
                else
                    end--;
                    
            }
            
            i++;
        }
            
        // Now, remove duplicate triplets using set
        
        set<vector<int>> s;
        
        for(int i=0;i<result.size();i++){
            s.insert(result[i]);
        }
        
      
        
        vector<vector<int>> final_result;
        
        for(auto it:s){
            final_result.push_back(it);
        }
        
return final_result;
    }
};