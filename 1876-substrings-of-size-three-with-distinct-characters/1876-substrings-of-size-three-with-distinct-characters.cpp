class Solution {
public:
    int countGoodSubstrings(string s) {
        
        
        //sliding window problem with window size 3
        
       map<char,int> mp;
        int counter;
       
        int i=0,j=0,k=3;
        
        while(j<s.size()){
            
            mp[s[j]]++;
            
            if((j-i+1)<k){
                j++;
            }
            
            else if((j-i+1)==k){
                
                //window reached
                
                if(mp.size()==k){
                    
                    for(auto it:mp){
                        
                        cout<<"\n"<<it.first<<"\n";
                        
                    }
                    counter++;
                }
                
                //remove i from window
                
                
              
                mp[s[i]]--;
                  cout<<s[i]<<mp[s[i]];
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                
                i++;
                j++;
                
            }
              
        }   
        
        return counter;
    }
};