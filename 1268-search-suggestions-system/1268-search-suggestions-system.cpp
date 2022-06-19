class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> result;
        
        map<string,set<string>> mp; // which prefix is matched to which strings
        
        for(int i=0;i<products.size();i++){
            
            string str=products[i];
            
            for(int j=1;j<=str.size();j++){
                mp[str.substr(0,j)].insert(str);
            }
            
            
        }
        
        // now find prefix for searchword
        
        for(int i=1;i<=searchWord.size();i++){
            
            vector<string> temp;
            
            set<string> ms=mp[searchWord.substr(0,i)];
        
            int counter=0;
            
          for(auto it:ms){
              counter++;
              if(counter<=3){
                  temp.push_back(it);
              }
              
          }
            result.push_back(temp);
            
        }
        
        
        
        return result;
        
    }
};