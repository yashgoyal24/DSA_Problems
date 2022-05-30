// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    
       map<char,int> mp;
        
        int i=0;
        int j=0;
        int maxi=0;
        
        while(j<S.size()){
                            
            mp[S[j]]++;
            
            if((j-i+1)<mp.size()){
                j++;
            }
            
            else if((j-i+1)==mp.size()){
                
                //window hit
                
                if(mp.size()>maxi)
                    maxi=mp.size();
             //   maxi=max(maxi,mp.size());
                j++;
                    
            
        }
            else if((j-i+1)>mp.size()){
                
                while((j-i+1)>mp.size()){
                    
                    //remove calculations for i
                    
                    mp[S[i]]--;
                    if(mp[S[i]]==0)
                        mp.erase(S[i]);
                    
                    i++;
                }
                
                 j++;
            }
            
       
    }
        return maxi;
}