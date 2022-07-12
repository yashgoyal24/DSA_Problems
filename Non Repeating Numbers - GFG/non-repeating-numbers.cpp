// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> result;
        // Code here.
        int xor1=0;
        for(auto it:nums){
            xor1^=it;
        }
        // xor has num1^num2
        // separate into buckets, find rightmost set bit
        
        int diff_bit_index=0;
        int cpy=xor1;
        int xr=1;
        while((cpy&1)==0){
            diff_bit_index++;
            cpy=cpy>>1;
        }
        int num=1<<diff_bit_index;
        int xr1=0,xr2=0;
        for(auto it:nums){
            if((it&num)==0){
                xr1=xr1^it;
            }
            else{
                xr2=xr2^it;
            }
        }
        if(xr1>xr2){
           result.push_back(xr2);
        result.push_back(xr1); 
        }
        else{
        result.push_back(xr1);
        result.push_back(xr2);
        }
        return result;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends