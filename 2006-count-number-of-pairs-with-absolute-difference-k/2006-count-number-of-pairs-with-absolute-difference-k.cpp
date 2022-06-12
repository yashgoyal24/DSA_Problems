class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<=nums.size()-2;i++){
            for(int j=i+1;j<=nums.size()-1;j++){
             if(abs(nums[i]-nums[j])==k)
                 count++;
            }
        }
        
       return count; 
    }
};