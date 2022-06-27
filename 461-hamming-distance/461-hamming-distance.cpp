class Solution {
public:
    int hammingDistance(int x, int y) {
        // first do xor, then find number of set bits
        int counter=0;
        int z=x^y;
        while(z>0){
            counter++;
            z=z&(z-1);
        }
        return counter;
    }
};