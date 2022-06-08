class Solution {
public:
    int removePalindromeSub(string s) {
        
        if(s.size()==0)
            return 0;
        
           else if(Pallindrome(s))
                return 1;
     
        else return 2;
    }
    
    bool Pallindrome(string s){
        
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
        
    }
};