class Solution {
public:
     
    bool compareStr(string &s1, string &s2){
        // s1 bada wala string hai
        if(s1.size()!=s2.size()+1)
            return false;
        else{
            // size same hai
            
            int fp=0;  // pointer for both the strings
            int sp=0;
            
            while(fp<s1.size()){
                
                if(sp<s2.size() && s1[fp]==s2[sp]){
                    fp++;
                    sp++;
                }
                else
                    fp++;
                
            }
            
            if(fp==s1.size() && sp==s2.size())
                return true;
            return false;
            
            
        }
    }
    
     static bool cmp(string &s1, string &s2){
        
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
         int n=words.size();
        return LSC(words, n, 0);
    }
    
     int LSC(vector<string>& nums,int n, int index){  // result vector store the LIS elements
        
        vector<int> result;
        vector<int> mapper(n,1); // to store LIS(i) at respective index i
      
        
        for(int index=1;index<n;++index){
            
            for(int prev=0;prev<index;++prev){
                
                if(compareStr(nums[index],nums[prev]) && 1+mapper[prev]>mapper[index]){ // write logic to compare the strings in separate function
                    
                    
                    mapper[index]=1+mapper[prev];
                }
                
            }
            
        }
    
        int maxi=0;
        for(auto it:mapper)
            maxi=max(maxi, it);
         
        return maxi;
    }
   
   
    
};