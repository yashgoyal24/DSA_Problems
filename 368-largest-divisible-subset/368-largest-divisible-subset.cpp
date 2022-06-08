class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
        return LDS(nums, n, 0);
    }
     vector<int> LDS(vector<int>& nums,int n, int index){  // result vector store the LIS elements
        
        vector<int> result;
        vector<int> mapper(n,1); // to store LIS(i) at respective index i
        vector<int> map_parent(n); // to store the parent index
       
        for(int i=0;i<n;i++){
            map_parent[i]=i;
        }
        
        for(int index=1;index<n;index++){
            
            for(int prev=0;prev<index;prev++){
                
                if(nums[index]%nums[prev]==0){
                    
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
        return result;
    }
};