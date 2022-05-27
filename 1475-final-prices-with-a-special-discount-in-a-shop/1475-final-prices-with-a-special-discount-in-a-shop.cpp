class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        vector<int> result;
        
        //problem is to calculate nearest smallest to right (NSR)
        
        stack<int> st;
        
        //start from last element to first
        
        for(int i=prices.size()-1;i>=0;--i){
            
            
            //if empty stack
            
            if(st.size()==0){
                result.push_back(prices[i]);
            }
            
            
            //not empty
            
            else{
                
                if(st.top()<=prices[i]){
                    result.push_back(prices[i]-st.top());
                }
                
                else{
                    while(st.size()>0 && st.top()>prices[i]){
                        st.pop();
                    }
                    if(st.size()>0)
                      result.push_back(prices[i]-st.top());
                    else
                        result.push_back(prices[i]);
                }
                
                
            }
            
            
            
            //push element to stack
            
            st.push(prices[i]);
        }
        
        //reverse to get correct order
        
        reverse(result.begin(),result.end());
        
        return result;
    }
};