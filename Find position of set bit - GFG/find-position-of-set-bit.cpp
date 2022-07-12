// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N==0)
        return -1;
        
        int cpy=N;
        int c=0;
        while(cpy>0){
            cpy=cpy&(cpy-1);
            cpy>>1;
            c++;
        }
        if(c>1)
        return -1;
        return log2(N)+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends