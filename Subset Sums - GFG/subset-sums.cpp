// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

  void F(vector<int> &arr,int N,int index,int sum,vector<int> &result){
            
            if(index>=N){
            result.push_back(sum);
            return;
            }
            // pick
            
            sum+=arr[index];
            F(arr,N,index+1,sum,result);
            
            //don't pick
            
            sum-=arr[index];
            F(arr,N,index+1,sum,result);
            
        }
    vector<int> subsetSums(vector<int> arr, int N)
    {
            vector<int> result;
        
            F(arr,N,0,0,result);
            
            return result;
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