class KthLargest {
    
    int k1;
    vector<int> nums1;
     priority_queue<int, vector<int>, greater<int>> minheap;
    
public:
    KthLargest(int k, vector<int>& nums) {
        k1=k;
        nums1=nums;
         for(int i=0;i<nums1.size();++i)
         {
            minheap.push(nums1[i]);
         }
      
        
    }
    
    int add(int val) {
        
        minheap.push(val);
         
          
            while(minheap.size()>k1){
                minheap.pop();
                
            }
            
        
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */