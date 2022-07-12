class Solution {
public:
    int getSum(int a, int b) {
        
        int exor=a^b;
        int and1=(unsigned)(a&b)<<1;
        
        return exor+and1;
        
        
        
    }
    
    
    

};