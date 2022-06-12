class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        // variable sized sliding window
        
        // condition is all unique elements in window
        
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        map<int,int> mp; // to store element and its count
        while(j<nums.size()){
            
            mp[nums[j]]++;
            
            if(j-i+1<mp.size()){ 
                
                j++;
            }
            
            else if(j-i+1==mp.size()){ // window hit, do wthat is required
                
                int sum=0;
                for(int k=i;k<=j;k++)
                    sum+=nums[k];
                maxi=max(maxi,sum);
                j++;
            }
            else if(j-i+1>mp.size()){
                
                // remove calculations of i
                
                while(j-i+1>mp.size()){
                    
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    i++;
                }
                
                
                
               j++; 
            }
            
            
            
            
        }
        return maxi;
    }
};