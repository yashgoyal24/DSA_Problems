// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
  
    
    
    
    
    int findPages(int A[], int N, int M) 
    {
       int low=0;
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    int high=sum;
    int res=-1;
    while(low<=high){
        
        
        int mid=low+(high-low)/2;
        if(isPossible(A,N,M,mid)){
            // try to reduce more
            res=mid;
            high=mid-1;
        }
        else{
            // since we are getting more students, we increase the max_limit
            low=mid+1;  
        }
        
        
        
        
    }
    
    return res;
    }
    
    
     bool isPossible(int A[],int N,int B,int max_limit){
    
    int stud_count=1;
    int books=0;
    for(int i=0;i<N;i++){
        if(books+A[i]<=max_limit){
            // no problem
            books+=A[i];
        }
        
        else{
            books=A[i];
            stud_count++;
            if(stud_count>B || books>max_limit){
                return false;
            }
            
        }
      
    }
    
    return true;
    
}
    
    
};


    

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends