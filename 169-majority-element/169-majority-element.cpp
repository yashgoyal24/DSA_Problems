class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj=0,count=0;
        for(auto it:nums){
            if(count==0){
                count++;
                maj=it;
            }
            else if(it==maj)
                count++;
            else
                count--;
        }
        
        return maj;
    }
};