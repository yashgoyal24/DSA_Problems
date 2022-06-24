class Solution {
public:
    vector<int> countBits(int n1) {
        
        vector<int> result;
        
        for(int i=0;i<=n1;i++){
        int counter=0;
        int n=i;
        while(n>0){
            n=n&(n-1);
            ++counter;
        }
            result.push_back(counter);
        }
        return result;
    }
};