class Solution {
public:
    int minBitFlips(int start, int goal) {
         int c=start^goal;
        
        //now calculate number of set bits and return it
        int counter=0;
        while(c>0){
            counter++;
            c=c&(c-1);
        }
        
        return counter;
    }
};