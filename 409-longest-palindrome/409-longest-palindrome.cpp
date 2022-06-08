class Solution {
public:
    int longestPalindrome(string s) {
        

        map<char,int> mp; // to store char and its frequency
        
        for(auto it:s){
            mp[it]+=1;
        }
        
    if(mp.size()==1) // only single character string, return its length
    return s.size();
        
        
        int result=0;
        int flag=0;
        for(auto it:mp){
            cout<<it.first<<it.second;
            if(it.second%2==0){
                result+=it.second;
            }
            else if(it.second%2==1){
                flag=1;
                mp[it.first]--;
                result+=(it.second-1);
            }
            
        }
        
     
        if(flag==1)
            return result+1;
        return result;
    }
    
  
};