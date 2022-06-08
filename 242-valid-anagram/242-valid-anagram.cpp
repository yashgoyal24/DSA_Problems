class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        map<char, int> mp1; // to store char and its count for s
        map<char, int> mp2;  // to store char and its count for t
        
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            mp2[t[i]]++;
        }
       for(auto it:mp1){
           
           if(mp1[it.first]!=mp2[it.first])
               return false;
           
       }
        return true;
    }
};