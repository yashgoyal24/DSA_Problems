class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        if(special.size()==1 && special[0]==top && special[0]==bottom)
            return 0;
        int maxi=0;
        
        ///sort special wala array
        
        sort(special.begin(),special.end());
        
        //traverse special array
        
        for(int i=0;i<special.size();i++){
            
            maxi=max(maxi,special[i]-bottom);
            bottom=special[i]+1;
            
        }
        
        //if any elements present after last special element
        
        maxi=max(maxi,top-bottom+1);
        
        return maxi;
    }
};