class Solution {

public:
    int percentageLetter(string s, char letter) {
     int counter=0;
        for(int i=0;i<s.length();i++){
            char n=s[i];
            if(n==letter)
                counter++;
    }
        
        return ((counter*100)/s.length());
    }
};
