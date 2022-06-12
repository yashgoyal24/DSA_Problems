class FindSumPairs {
public:
vector<int> nums1,nums2;
 unordered_map<int,int> mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
       
          for(auto it:nums2)
            mp2[it]++;
        
      //  sort(nums2.begin(),nums2.end());
      
    }
    
    void add(int index, int val) {
        mp2[nums2[index]]--;
        if(mp2[nums2[index]]==0)
            mp2.erase(nums2[index]);
        nums2[index]+=val;
        mp2[nums2[index]]++;

    }
    
    int count(int tot) {
        
        int result=0;
       
        for(int i=0;i<nums1.size();i++){
            int ele1=nums1[i];
            int ele2=tot-ele1;
          
                
                if(mp2.find(ele2)!=mp2.end()){
                    result+=mp2[ele2];
                }
           
            }
            
            
           
            
        
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */