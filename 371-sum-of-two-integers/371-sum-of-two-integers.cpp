class Solution {
public:
    int getSum(unsigned a, unsigned b) {
        
        int sum,carry;
        while(carry!=0){
            
            sum=a^b;
            carry=(a&b)<<1;
            a=sum;
            b=carry;
            
        }
        
        
       return sum; 
    }
    
    
    

};