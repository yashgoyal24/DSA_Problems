class Solution {
    
vector<int> nsl; 
vector<int> nsr; 
public:
    int largestRectangleArea(vector<int>& temperatures) {
        
       
        nextSR(temperatures);
        nextSL(temperatures);
         int maxi=0;
     
       vector<int> width;
        vector<int> area;
      
        for(int i=0;i<nsl.size();i++){
            width.push_back(nsr[i]-nsl[i]-1);
            area.push_back(width[i]*temperatures[i]);
            maxi=max(maxi,area[i]);
        }
        
        
        
        
        return maxi;
    }
    
    
    void nextSR(vector<int>& temperatures){
        
            stack<pair<int,int>> st;
        
        for(int i=temperatures.size()-1;i>=0;--i){
            
            if(st.size()==0){
                
                nsr.push_back(temperatures.size());
                
                
            }
            
            else{
                
                if(st.top().first<temperatures[i]){
                    nsr.push_back(st.top().second);
                
                    
                }
                else{
                    while(st.size()>0 && st.top().first>=temperatures[i]){
                        
                        st.pop();
                        
                    }
                    if(st.size()>0)
                        nsr.push_back(st.top().second);
                    else
                         nsr.push_back(temperatures.size());
                }
                
            }
            st.push({temperatures[i],i});
            
        }
        
        reverse(nsr.begin(),nsr.end());
       
    }
    
    
    
    
     void nextSL(vector<int>& temperatures){
        
            stack<pair<int,int>> st;
        
        for(int i=0;i<temperatures.size();++i){
            
            if(st.size()==0){
                
                nsl.push_back(-1);
                
                
            }
            
            else{
                
                if(st.top().first<temperatures[i]){
                    nsl.push_back(st.top().second);
                    
                }
                else{
                    while(st.size()>0 && st.top().first>=temperatures[i]){
                        
                        st.pop();
                        
                    }
                    if(st.size()>0)
                        nsl.push_back(st.top().second);
                    else
                         nsl.push_back(-1);
                }
                
            }
            st.push({temperatures[i],i});
            
        }
       
    }
};