class Solution {
public:
    int maxProduct(vector<string>& words) {
        
     
    
        //store letters of all words in a set
        
        vector<set<char>> s;
        
        for(int i=0;i<words.size();i++){
            
            set<char> charset;
            
            for(int j=0;j<words[i].size();j++){
                
                charset.insert(words[i][j]);
                
            }
            
            s.push_back(charset);
            
        }
        
        
        int maxi=0;
        
        for(int i=0;i<s.size()-1;++i){
            
        
            for(int j=i+1;j<s.size();++j){
                
               bool flag=true;
    
         
               for(auto it:s[i]){
                    if(s[j].find(it)!=s[j].end()){
                        
                        //letter present in word2 so ignore the word
                        
                        flag=false;
                        break; 
                    }
                    
                
                }
                if(flag==true){
                    int val=words[i].size()*words[j].size();
                maxi=max(maxi,val);
                }
                
                
            }
            
            
        }
         
        
       return maxi; 
        
    }
    
    
};