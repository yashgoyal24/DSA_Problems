// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    
public:

vector<int> result;
vector<int> ds;
int sum=0;
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        Func(arr, N, 0);
        return result;
       
    }
    
    void Func(vector<int> arr, int N, int idx){
        
         if(idx>=N){
             result.push_back(sum);
            // sum=0;
            return;
        }
        
        
        // pick
        
        sum+=arr[idx];
      //  ds.push_back(arr[idx]);
        Func(arr,N,idx+1);
        
        // remove from ds
        
        sum=sum-arr[idx]; // since it is already included 
      //  ds.pop_back();
        
        // no pick
        
        Func(arr,N,idx+1);
        
       
        
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends