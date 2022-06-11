class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        
          int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int start_idx = 0;
        bool found = false;
        for (int end_idx = 0; end_idx < n; end_idx++) {
            curr_sum += nums[end_idx];
            while (start_idx <= end_idx && curr_sum > target) {
                curr_sum -= nums[start_idx];
                start_idx += 1;
            }
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, end_idx - start_idx + 1);
            }
        }
        return found ? n - max_len : -1;
        
 /*       // find longest subarray with sum= (total_sum) - x and then return nums.size()-value obtained
        int sum1=0;
        for(auto it:nums){
            sum1+=it;
        }
        sum1=sum1-x;
        int maxi=-1;
        int sum=0;  //to store prefix sum
        
        //map to store prefix sum and its index, store only first time index, since need to find largest 
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
            if(sum==sum1){
                
                maxi=max(maxi,i+1);
                
            }
            
            else if(mp.find(sum-sum1)!= mp.end()){
                
                //already present
                
                maxi=max(maxi,i-mp[sum-sum1]);
              //  cout<<maxi;
             
                
            }
           
            mp[sum]=i;
            cout<<sum<<":"<<mp[sum]<<"\n";
          //  cout<<mp[sum]<<"\n";
        
        }
   
     
        if(maxi!=-1)
        return nums.size()-maxi;
            else return -1;*/
        
    }
};