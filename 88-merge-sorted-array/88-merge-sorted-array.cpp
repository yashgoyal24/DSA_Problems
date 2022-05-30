class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    
        if(m>0 && n!=0){   //elements present in nums1
            
            int i=0;
            int j=0;
            
           while(i<m){
               
               if(nums1[i]<=nums2[0])
                   i++;
               else { // >
                   swap(nums1[i],nums2[0]);
                   i++;
                   //put nums[j] in correct position
                   int je=0;
                   while(je<nums2.size()-1 && nums2[je]>nums2[je+1]){
                       swap(nums2[je],nums2[je+1]);
                       je++;
                   }
                   
                   
               }
           }
            
            //after nums1 exhausted
            
            int idx=m;
            
            while(j<nums2.size()){
                
                nums1[j+idx]=nums2[j];
                
                
                j++;
            }
       
            
              for(auto it:nums1){
        cout<<it<<"\n";    
        }
          
            
            
        }
        
      
        

        else if(n!=0 && m==0){
            //no element in nums1, so simply copy nums2
            
            for(int i=0;i<nums2.size();i++){
                
                nums1[i]=nums2[i];
                
            }
        }
        
    }
};