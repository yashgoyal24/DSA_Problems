class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //put all elements in a set
        
        if(nums.empty()){
            return 0;
        }
        
        set<int> s;
        
        for(auto it:nums)
            s.insert(it);
        
        int maxi=1;
        
       //start traversing from start till end 
        
        for(int i=0;i<nums.size();i++){
            
           int counter=0;
            
            if(s.find(nums[i]-1)!=s.end()){ //previous element found
                continue;
            }
            else if(s.find(nums[i]-1)==s.end()){  //no previous
                
               
                while(s.find(nums[i]+counter)!=s.end()){
                    counter++;
                }
                
            }
            maxi=max(maxi,counter);
        }
        
        return maxi;
    }
};