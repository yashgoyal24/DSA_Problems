class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1)
            return false;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' ||s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                
            }
            else{
                if(st.size()==0) // no opening bracket for a closing bracket
                    return false;
                else{
                    
                    char ch=st.top();
                    
                    if(ch=='(' && s[i]!=')' || ch=='[' && s[i]!=']' || ch=='{' && s[i]!='}'){
                        
                        return false;
                    }
                      st.pop();  
                 
                    
                }
                
                }
            }
        if(st.size()>0)
        return false;
        else return true;
        }
    
};