class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // same as aggressive cows problem for maximizing the minimum gap
    
    sort(position.begin(),position.end());
    
    int n=position.size();
        
        //set low and high for binary search
   int low=1;
    int high=1e9;
    int result=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(isPossible(mid, position, n, m)){
            result=mid;
            low=mid+1; // beacuse we need to maximize
        }
        else{
            high=mid-1;
        }
        
        
    }
    
    return result;
    }
     bool isPossible(int x, vector<int> A,int n, int m){
        int current_pos=0;
        int current_count=1;
    
        for(int i=1;i<n;i++){
            
            if(A[i]-A[current_pos]>=x)
            
          {
              current_count++;
                if(current_count==m)
                    return true;
                current_pos=i;
          }
            // now diff is greater than or equal to x
           
        }
      
        return false;
    }
};