class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        // sliding window of window size = size of string p
        
        int k=p.size();
        int i=0,j=0;
        vector<int> result; // to store resultant indices
        map<char, int> mp; // store char vs count for p string
  
        
        
        for(auto it:p){
            mp[it]++;
        }
        
        int count=mp.size();  // denotes number of distinct characters in map
        
        while(j<s.size()){
            
          mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
            
            if(j-i+1<k)
                j++;
            
            else if(j-i+1==k){
                 // do required calculations since window size hit now
                
                if(count==0) // anagram found
                    result.push_back(i);
                
                // remove calculations for i and then slide the window
                
                mp[s[i]]++;
                if(mp[s[i]]==1)
                    count++;
                
                i++;
                j++;
                
                
                
            }
            
            
            
            
            
        }
       return result; 
    }
};