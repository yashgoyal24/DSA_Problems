class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        return LIS(nums, n, 0);
        
    }
    
    int LIS(vector<int>& nums,int n, int index){  // result vector store the LIS elements
        
        vector<int> result;
        vector<int> mapper(n,1); // to store LIS(i) at respective index i
        vector<int> map_parent(n); // to store the parent index
       
        for(int i=0;i<n;i++){
            map_parent[i]=i;
        }
        
        for(int index=1;index<n;index++){
            
            for(int prev=0;prev<index;prev++){
                
                if(nums[index]>nums[prev]){
                    
                    if(1+mapper[prev]>mapper[index]){
                        // set new parent
                        map_parent[index]=prev;
                    }
                    mapper[index]=max(mapper[index], 1+mapper[prev]);
                }
                
            }
            
        }
    
        int maxi=0;
        for(auto it:mapper)
            maxi=max(maxi, it);
        
        // find index of maxi in nums
        
        int max_index=-1;
        
        for(int i=0;i<n;i++){
            if(mapper[i]==maxi){
                max_index=i;
                break;
            }
            
        }
      
        // push max_index wala element
        
        result.push_back(nums[max_index]);
        
       
        // start pushing parents from max_index onwards
        
        while(result.size()!=maxi){
            
            result.push_back(nums[map_parent[max_index]]);
            int temp=map_parent[max_index];
            max_index=temp;
         
            
        }
       
        reverse(result.begin(),result.end());
         for(auto it:result)
            cout<<it;
        return maxi;
    }
    
    
   /* int LIS(vector<int> &nums,int n, int curr, int prev){   // RECURSION APPROACH
        
        if(curr==n)
            return 0;
        int len2=0;
        int len1=LIS(nums, n, curr+1, prev); // not pick
        if(prev==-1 || nums[curr]>nums[prev])  // pick case
            len2=1+LIS(nums,n,curr+1,curr);
      
        return max(len1, len2);
        
    }*/
    
  /*  int LIS(vector<int> &nums,int n, int curr, int prev){  // DP APPROACH
        
        int dp[n+1][n+1];  // curr and prev
    for(int i=0;i<=n;i++){
        dp[n][i]=0;  // base case
    }
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                
           int len2=0;     
        int len1=dp[i+1][j+1]; // not pick
        if(j==-1 || nums[i]>nums[j])  // pick case
            len2=1+dp[i+1][i+1];
      
        dp[i][j+1]=max(len1, len2);
            }
        }
        return dp[0][0];
    }*/
    
    
    
};