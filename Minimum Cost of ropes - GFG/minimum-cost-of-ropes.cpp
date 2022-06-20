// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if(n==1)
        return 0;
        // we can use min heap here
        long long result=0;
        priority_queue<long long,vector<long long>,greater<long long>> min_heap;
        
        for(int i=0;i<n;i++){
            min_heap.push(arr[i]);
        }
        
        while(min_heap.size()>1){
            long long f=min_heap.top();
            min_heap.pop(); // 1st minimum
            long long s=min_heap.top(); // 2nd minimum
            min_heap.pop();
            result=result+f+s;
            min_heap.push((f+s));
            
        }
        
     //   result+=min_heap.top();
        
        return result;
        
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends