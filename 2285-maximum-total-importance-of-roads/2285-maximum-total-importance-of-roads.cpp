class Solution {
public:
    
     static int cmp1(const pair<int,int> &a,const pair<int,int> &b){
        
        return (a.second > b.second);
        
    }
    
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long result=0;
        
        //map storing node and its respective degree
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            
            mp[i]=0;
            
        }
        
        for(int i=0;i<roads.size();i++){
            
            vector<int> edge=roads[i];
            mp[edge[0]]++;
            mp[edge[1]]++;
            
        }
        
        
        
        
        //convert map to pair for sorting purposes
        
        vector<pair<int,int>> v(mp.begin(),mp.end());
        
        //sort according to value in desc order
        
        sort(v.begin(),v.end(),cmp1);
    
    //assign mapping from 0 to n-1
        
        vector<int> final_val(n);
        
        int value1=n;
        
        for(int i=0;i<n;i++){
            
            final_val[v[i].first]=value1;
            value1--;
            
        }
        
        cout<<"Final Values Assigned to nodes";
        for(auto it:final_val){
            
            cout<< it<<"\n";
            
        }
        
        //store in result
        
        for(int i=0;i<roads.size();i++){
            
            vector<int> edge=roads[i];
           
            result+=final_val[edge[0]]+final_val[edge[1]];
        }
        
        
        return result;
    }
    
    
   
};