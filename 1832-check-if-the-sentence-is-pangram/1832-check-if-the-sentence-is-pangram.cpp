class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        map<int,int> mp;
        for(int i=97;i<=122;i++)
            mp[i]=1;
        int count=26;
        for(auto it:sentence)
            if(mp.find((int)it)!=mp.end()){
                mp[(int)it]--;
                if(mp[(int)it]==0)
                    mp.erase((int)it);
            }
        if(mp.size()==0)
            return true;
        return false;
    }
};