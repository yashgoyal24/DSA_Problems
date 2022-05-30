// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         
         
          vector<vector<int>> result;
        
        //sort according to first value;
        
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();i++){
            
            if(result.size()==0 || intervals[i][0] > result.back()[1]){
                
                //form a new entry and push into data structure
                
                result.push_back({intervals[i][0],intervals[i][1]});
                
            }
            else{
                
                //merge with last entry in the data structure
                
               result.back()[1]=max(intervals[i][1],result.back()[1]);
                
            }
            
        }
    
        return result;
         
         
         
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends