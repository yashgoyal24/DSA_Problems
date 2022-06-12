class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //sliding window problem
        
        // maintain a map for char and its count
        
        map<char,int> mp;
        
        int i=0;
        int j=0;
        int maxi=0;
        
        while(j<s.size()){
                            
            mp[s[j]]++;
            
            if((j-i+1)<mp.size()){
                j++;
            }
            
            else if((j-i+1)==mp.size()){
                
                //window hit
                
                if(mp.size()>maxi)
                    maxi=mp.size();
             //   maxi=max(maxi,mp.size());
                j++;
                    
            
        }
            else if((j-i+1)>mp.size()){
                
                while((j-i+1)>mp.size()){
                    
                    //remove calculations for i
                    
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    
                    i++;
                }
                if(j-i+1==mp.size()){
                    maxi=max(maxi,j-i+1);
                }
                 j++;
            }
            
       
    }
        return maxi;
    }
};