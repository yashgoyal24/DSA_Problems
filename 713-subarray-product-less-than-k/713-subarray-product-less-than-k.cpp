class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        // use sliding window approach
        
        int i=0;
        int j=0;
        int product=1;
        int counter=0;
        while(j<nums.size()){
            
            product*=nums[j];
        
            if(product<k){
                counter+=(j-i+1);
                j++;
            }
            
            else{
                
                while(product>=k && i<=j){
                    
                    product=product/nums[i];
                    i++;
                    
                }
               if(product<k){
                   counter+=(j-i+1);
                }
                j++;
            }
            
            
            
            
        }
        
        return counter;
        
    }
};