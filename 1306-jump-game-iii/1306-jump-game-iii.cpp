class Solution {
public:
    bool F(vector<int>&arr,int index,vector<int>&dp,vector<int>&visited){
         
        if(index>=arr.size() or index<0){
            return false;
        }
        if(arr[index]==0){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        bool f1=false,f2=false;
       if(visited[index]==0){
          visited[index]=1;
            f1=F(arr,index+arr[index],dp,visited);
            f2=F(arr,index-arr[index],dp,visited);
        }
    
        return dp[index]=f1 or f2;
        
        
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),-1);
        vector<int> visited(arr.size(),0);
       return F(arr,start,dp,visited);
    }
};