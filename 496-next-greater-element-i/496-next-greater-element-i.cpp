class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // find NGR for elements of array nums2
        
        //use map to store number and its ngr as value
        
        map<int,int> mp;
       
        
        stack<int> st;
        
        //start from last element to first
        
        for(int i=nums2.size()-1;i>=0;--i){
            
            
            //if empty stack
            
            if(st.size()==0){
                mp[nums2[i]]=-1;
            }
            
            
            //not empty
            
            else{
                
                if(st.top()>nums2[i]){
                    mp[nums2[i]]=st.top();
                }
                
                else{
                    while(st.size()>0 && st.top()<nums2[i]){
                        st.pop();
                    }
                    if(st.size()>0)
                      mp[nums2[i]]=st.top();
                    else
                        mp[nums2[i]]=-1;
                }
                
                
            }
            
            
            
            //push element to stack
            
            st.push(nums2[i]);
        }
        
      
       
        
        //now traverse nums1 and push in vector
        
        vector<int> final_ans;
        
        for(int i=0;i<nums1.size();i++){
            
        
          final_ans.push_back(mp[nums1[i]]);
         
            
        }
        
        
        return final_ans;
        
        
    }
};