class Solution {
public:
    int minSteps(string s, string t) {
          int steps=0;
        
        // create a map for both
        
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto it:s){
            mp1[it]++;
        }
          for(auto it:t){
            mp2[it]++;
        }
        
        // now traverse in mp1 and then compare with mp2
        
        for(auto it:mp1){
            
            char c=it.first;
            
            if(mp2.find(c)!=mp2.end()){
                
                // character mp2 me bhi mil gaya
         
                    steps=steps+(abs(mp1[c]-mp2[c]));
    
                
            }
            
            else{
                // mp1 wala character mp2 me nahi hai, to sidha add kar denge value
                
                steps=steps+mp1[c];
            }
            
            }
        
        for(auto it:mp2){
            char c=it.first;
            
            if(mp1.find(c)!=mp1.end())
                continue;  // case already handle kar liya hai
            else{
                steps+=mp2[c];
            }
            
        }
        
       return steps; 
    }
};