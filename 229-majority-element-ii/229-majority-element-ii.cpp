class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int maj1=-1,maj2=-1,c1=0,c2=0;
        for(auto it:nums){
            
             if(it==maj1)
                c1++;
            else if(it==maj2)
            c2++;
            else if(c1==0){
                c1++;
                maj1=it;
            }
           
          
            else if(c2==0){
                c2++;
                maj2=it;
            }
          
            else{ // current element not equal to both
                c1--;
                c2--;
            }
            
            
        }
        
        // check if candidate are actually major or not
        
        int count1=0,count2=0;
        cout<<maj1;
        for(auto it:nums){
            if(it==maj1)
                
                count1++;
            if(it==maj2)
                count2++;
            
            
        }
        
        vector<int> result;
        int maj_count=nums.size()/3;
        if(count1>maj_count)
            result.push_back(maj1);
        if(count2>maj_count && maj2!=maj1)
            result.push_back(maj2);
        
        return result;
        
    }
};