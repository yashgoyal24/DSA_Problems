class Solution {
public:
    int minDeletions(string s) {
        
        map<char,int> mp; // frequency v/s char array
        
        for(auto it:s){
            mp[it]++;
        }
        
        vector<int> temp;
        
        for(auto it:mp){
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end(),greater<int>()); // decreasing order
        int counter=0;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i]==0){
                while(i<temp.size()){
                    counter+=temp[i];
                    i++;
                }
                break;
            }
            if(temp[i]==temp[i+1]){

                temp[i+1]--;
                counter++;
            }
            else if(temp[i+1]>temp[i]){
                int tempo=temp[i]-1;
                counter+=(temp[i+1]-tempo);
                temp[i+1]=tempo;
                
            }
            else
                continue;
           
        }
        
        
        return counter;
    }
};