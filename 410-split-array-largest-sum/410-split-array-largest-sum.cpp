class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
      
        // problem is same as book allocation problem, minimize maximum
        
      //  sort(nums.begin(),nums.end()); sorting ki zarurat nahi hai
        
        int low=0; // maximum sum ka minimum value 
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
            sum+=it;
        int high=sum; // max sum ka highest value
        int result=-1;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            if(isPossible(nums,n,m,mid)){
                cout<<mid<<"true"<<"\n";
                result=mid;
                high=mid-1; // aur minimize karne ka try karo
            }
            else{
                // itne me possible nahi hua, to sum badhna chaiye
               cout<<mid<<"false"<<"\n";
               low=mid+1;
                
            }
               
        }
        return result;
    }
    
    
    
    bool isPossible(vector<int> nums,int n, int m, int max_capacity){
        
        int count=1;
        int sum=nums[0];
        if(sum>max_capacity)
            return false;
        for(int i=1;i<n;i++){
            
            if(sum+nums[i]<=max_capacity){
                sum+=nums[i];
            }
            else{
                count++;
                sum=nums[i];
            }
            if(count>m || nums[i]>max_capacity)
                return false;
            
        }
      
       return true ;
    }
};