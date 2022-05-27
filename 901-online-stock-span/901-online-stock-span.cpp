class StockSpanner {
public:
    
    //pair stores the NGL element and the corresponding index;
    
    //This is NGL problem to compute NGL index for all the elements
    
    stack<pair<int,int>> st;
    vector<int> result;
    
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int last_index=result.size()-1;
        if(st.size()==0){
            result.push_back(1);
             st.push({price,last_index+1});
            return 1;
        }
        else{
            
               if(st.top().first>price){
                    result.push_back((last_index+1)-st.top().second);
                  
                }
                
                else{
                    while(st.size()>0 && st.top().first<=price){
                        st.pop();
                    }
                    if(st.size()>0)
                      result.push_back((last_index+1)-st.top().second);
                    else
                      result.push_back(last_index+1+1);
                }
            
            
            
            
        st.push({price,last_index+1});
        
        return result[result.size()-1];
            
        }
        
       
        
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */