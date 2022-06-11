class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=1;
        int sum=0;
        for(auto it:weights)
            sum+=it;
        int high=sum;
        int n=weights.size();
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(isPossible(weights,days,n,mid)){ // possible hai to minimize karo
                
                result=mid;
                high=mid-1;
                
            }
            else{
                // current capacity me nahi ho raha, to capacity badha denge
                low=mid+1;
                
            }
        }
        return result;
    }
    
    bool isPossible(vector<int> weights, int days, int n, int max_capacity){
        
        int count=1;
        int sum=weights[0];
        if(sum>max_capacity)
            return false;
        for(int i=1;i<weights.size();i++){
            if(weights[i]>max_capacity)
                return false;
            if(sum+weights[i]<=max_capacity)
                sum+=weights[i];
            else{
                
                //capacity exceed  ho gaya
                
                count++;
                sum=weights[i];
            }
            if(count>days) // limit exceeded
                return false;
            
        }
        
        
        return true;
    }
};