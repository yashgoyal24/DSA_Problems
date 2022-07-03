// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans=new int[2];
        
        int xor_all=0;
        for(int i=1;i<=n;i++){
            xor_all=xor_all^i;
    }
    
  
    for(int i=0;i<n;i++){
        xor_all=xor_all^arr[i];
    }
    
    int rep_xor_miss=xor_all;
    
    int diff_bit_index=0;
    int cpy=rep_xor_miss;
   /* while(cpy & 1 !=1){
        diff_bit_index++;
        cpy=cpy>>1;
        
    }*/
    
    int xor1=0;
    int xor2=0;
    int num=xor_all & ~(xor_all - 1);;
    for(int i=0;i<n;i++){
        if((arr[i] & num)==0){
            xor1=xor1^arr[i];
        }
        else{
            xor2=xor2^arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if((i & num)==0){
            xor1=xor1^i;
        }
        else{
            xor2=xor2^i;
        }
    }
    int rep=0,missing=0;
    for(int i=0;i<n;i++){
        
        if(arr[i]==xor1){
            // repeating element
            rep=arr[i];
            missing=xor2;
            break;
        }
        else if(arr[i]==xor2){
            rep=xor2;
            missing=xor1;
            break;
        }
        
    }

    
  //  cout<<xor1<<xor2;
    ans[0]=rep;
    ans[1]=missing;
       return ans; 
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends