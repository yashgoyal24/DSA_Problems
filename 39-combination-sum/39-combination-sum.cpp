class Solution {
public:
    
int sum=0;
vector<vector<int>> result;
vector<int> ds;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        Func(candidates,target,0);
        return result;
    }
    
    void Func(vector<int>& candidates, int target, int idx){
        
        if(idx>=candidates.size()){  // no sum found
           if(sum!=target)
            return;
            else if(sum==target){
            //include ds in result
            result.push_back(ds);
            return;
        }
                
        }
        
        if(sum==target){
            result.push_back(ds);
            return;
        }
       
        
        // pick
        
         if(sum<=target){
        
        sum+=candidates[idx];
     
        ds.push_back(candidates[idx]);
      
        Func(candidates,target,idx); // since we can choose multiple number of times
        
        
        
        // not pick
        
        ds.pop_back();
        sum=sum-candidates[idx];
        Func(candidates,target,idx+1);
        
         }
        
    }
};