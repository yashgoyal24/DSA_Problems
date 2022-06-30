class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        if(n%2==1){
            // odd size
            int median=nums[n/2];
            for(int i=0;i<n;i++){
                res+=abs(nums[i]-median);
            }
            return res;
            
            
        }
        else{
            // even
            int med1=nums[n/2];
            int med2=nums[n/2-1];
            int res1=0;
            int res2=0;
            
            for(int i=0;i<n;i++){
                res1+=abs(nums[i]-med1);
            }
            
             for(int i=0;i<n;i++){
                res2+=abs(nums[i]-med2);
            }
            
            
            return max(res1,res2);
        }
        
        
        
       return res; 
    }
};