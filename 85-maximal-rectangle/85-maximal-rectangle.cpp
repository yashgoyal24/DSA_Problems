class Solution {
public:
    
vector<int> nsl; 
vector<int> nsr; 
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        //convert 2d matrix to 1d matrix and apply maximum area of histogram function
        
        int maxi=0;
        
        vector<int> mat;
     
        //char array to integer array
        
        for(auto it:matrix[0]){
            if(it=='0')
            mat.push_back(0);
            else
                mat.push_back(1);
          
        }
       // mat.push_back(temp);
        vector<int> h{2,0,2,1,1};
        
        for(auto it:mat){
            cout<<it<<"\n";
            
        }
        int result=largestRectangleArea(mat);
        nsl.clear();
            nsr.clear();
        maxi=max(maxi,result);
       // cout<<"result"<<result;
        for(int i=1;i<matrix.size();i++){
            
            for(int j=0;j<matrix[i].size();j++){
                
                if(matrix[i][j]=='0')
                   mat[j]=0;
                else
                     mat[j]++;
                
            }
             for(auto it:mat){
            cout<<"new row"<<it<<"\n"; }
            result=largestRectangleArea(mat);
            
            cout<<result;
            maxi=max(maxi,result);
             nsl.clear();
            nsr.clear();
            cout<<"maxi"<<maxi;
        }
        return maxi;
    }
    
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