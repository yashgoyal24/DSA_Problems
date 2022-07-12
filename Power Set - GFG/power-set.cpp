// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> result;
		    int n=s.size();
		    for(int i=0;i<=((1<<n)-1);i++){
		        string str;
		        for(int j=0;j<n;j++){
		            
		            // check if ith bit is set or not, and add accordingly
		            
		            if((i&(1<<j))!=0){
		                // bit is set, so add in result
		                str.push_back(s[j]);
		              
		            }
		        }
		        
		        
		        result.push_back(str);
		        
		    }
		    
		    
		    sort(result.begin(),result.end());
		    result.erase(result.begin());
		    return result;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends