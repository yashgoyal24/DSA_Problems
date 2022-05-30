// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        
        
        long long sum=0;
        long long max_sum=INT_MIN;      //since atleast 1 element is present
        
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            
            max_sum=max(max_sum,sum);
            
            if(sum<0)
            sum=0;     //since negative number will decrease the current sum, so start with a new window
            
        }
        
        
        
        return max_sum;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends