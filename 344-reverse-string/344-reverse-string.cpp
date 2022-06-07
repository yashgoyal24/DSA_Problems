class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n=s.size();
        
       // for(int i=0;i<n/2;i++){
          //  swap(s[i],s[n-i-1]);
          //  int initial=s[i];
          //  s[i]=s[n-i-1];
          //  s[n-i-1]=initial;
            
            
       // }
        reverse(s.begin(),s.end());
        
        for(int i=0;i<n;i++){
            cout<<s[i];
        }
     
    }
};