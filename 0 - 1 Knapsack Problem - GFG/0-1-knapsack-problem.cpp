// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       // using bottom up approach 
       
       int dp[1001][1001];   // n+1, w+1
        
       // base case
       
       for(int i=0;i<=n;i++){
           dp[i][0]=0;
       }
       for(int j=0;j<=W;j++){
           dp[0][j]=0;
       }
       
      for(int i=1;i<=n;i++){
          
          for(int j=1;j<=W;j++){
              
              if(wt[i-1]<=j){
                  // include or don't include
                  dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
              }
              else{
                  
                  // don't include
                  
                  dp[i][j]=dp[i-1][j];
              }
              
          }
          
      }
       
      return dp[n][W] ;
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends