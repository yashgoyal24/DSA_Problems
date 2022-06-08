class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int i=0;
        int j=1;
        int result=1;
        int maxi=-1;
        while(j<nums.size()){
            if(nums[j]>nums[i]){
                 result++;
               
            }
            else{
            
                 result=1;
            }
            maxi=max(maxi,result); 
             j++;
            i++;
       
        }
        return maxi;    
    }
};