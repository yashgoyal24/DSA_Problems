class Solution {
public:
    
    static bool cmp(string s1,string s2){
        return s1.size()>s2.size(); // decreasing order of lengths
    }
    
    

    
    int minimumLengthEncoding(vector<string>& words) {
        
        
    /*    // make a set of words to eliminate dupicates
        sort(words.begin(),words.end(),cmp);
        
        unordered_map<string,vector<string>> mp; // to store string and its corresponding suffix
        
        for(int i=0;i<words.size();++i){
            
           // check if word present in map (value part)
            
            bool flag=false;
            for(auto it:mp){
                
               vector<string> temp=it.second;
                for(auto it1:temp){
                    if(it1==words[i]){
                        flag=true;
                        break;
                    }
                }
                
                
            }
            
            if(flag==true) // found in map
                continue;
                vector<string> tempo;
                for(int j=words[i].size()-1;j>=0;j--){
                    
                    string temp=words[i].substr(j); // suffix starting from last index
                    tempo.push_back(temp);
                 
                    
                }
                   mp[words[i]]=tempo;
                
            
            
        }
        
        // Now traverse in map
        int result=0;
        for(auto it:mp){
            result+=(it.first.size());
        }
        result+=mp.size();
        return result;
        
        
    }*/
     sort(words.begin(),words.end(),cmp);
        string res="";
        res=res+words[0]+"#";
        
        for(int i=1;i<words.size();i++){
            
            int pos=res.find(words[i]+"#");
            if(pos!=-1)
                continue;
            else
                res+=words[i]+"#";
            
        }
        
        return res.size();
    }
};