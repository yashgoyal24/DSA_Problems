class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // find NGR for elements of array nums2
        
        
         vector<int> result;
        
        
        stack<int> st;
        
        //start from last element to first
        
        for(int i=nums2.size()-1;i>=0;--i){
            
            
            //if empty stack
            
            if(st.size()==0){
                result.push_back(-1);
            }
            
            
            //not empty
            
            else{
                
                if(st.top()>nums2[i]){
                    result.push_back(st.top());
                }
                
                else{
                    while(st.size()>0 && st.top()<nums2[i]){
                        st.pop();
                    }
                    if(st.size()>0)
                      result.push_back(st.top());
                    else
                        result.push_back(-1);
                }
                
                
            }
            
            
            
            //push element to stack
            
            st.push(nums2[i]);
        }
        
        //reverse to get correct order
        
        reverse(result.begin(),result.end());
        
    
        
        //result contains NGR for nums2
        
        //now traverse nums1 and push in vector
        
        vector<int> final_ans;
        
        for(int i=0;i<nums1.size();i++){
            
        
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    final_ans.push_back(result[j]);
                    break;
                }
                
            }
            
         
            
        }
        
        
        return final_ans;
        
        
    }
};