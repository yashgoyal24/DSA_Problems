class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
     
        if(nums.size()==1 && nums[0]<k){
             return 1;
        }
           
        
        // use sliding window 
        
        int i=0,j=0;
         long long counter=0;
        long long sum=0;
      
        while(j<nums.size()){
            
            
            sum=sum+nums[j];
            
            if(sum*(j-i+1)<k){
                counter=counter+(j-i+1); // ending at jth index, sabko add kardo previous count mei
                j++;
            }
               
            else if(sum*(j-i+1)>=k){
                
                while(sum*(j-i+1)>=k && i<=j){
                    //remove calculations for i
                    sum=sum-nums[i];
                    
                    i++;
                    
                }
                if(sum<k)
                    counter=counter+(j-i+1);
                j++;
            }
            
            
            
            
        }
        return counter;
    }
};