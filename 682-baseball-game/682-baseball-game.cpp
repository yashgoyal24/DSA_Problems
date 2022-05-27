class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum=0;
        for(int i=0;i<ops.size();++i){
            
            if(ops[i]=="+"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.push(num1);
                st.push(num1+num2);
            }
            else if(ops[i]=="D"){
                int num1=st.top();
                st.push(2*num1);
            }
            else if(ops[i]=="C"){
                st.pop();
            }
            else{
                //Integer
                st.push(stoi(ops[i]));
            }
            
        }
        
        while(st.size()>0){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};