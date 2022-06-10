class Solution {
public:
    int reverse(int x) {
        
        string s=to_string(x);
        string s1="";
       bool flag=false;
        if(s[0]=='-'){ // negative number
            flag=true;
            for(int i=1;i<s.size();i++){
                s1.push_back(s[i]);
            }
            
            
        }
        else
            s1=s;
        std::reverse(s1.begin(), s1.end());  
        if(flag==true){
            // negative number
            s1.insert(s1.begin(),'-');
            
        }
        
        long result=stol(s1);
        if(result>INT_MAX || result<INT_MIN)
            return 0;
        cout<<result;
        return result;
    }
};