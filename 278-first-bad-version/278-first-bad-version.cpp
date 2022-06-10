// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low=0;
        int high=n-1;
        
        while(low<=high){
            
           int mid=low+(high-low)/2;
        
            if(isBadVersion(mid+1))
                high=mid-1; // to return first occurence
            else 
                // mid ke right pe bad version hoga, kyuki left me hota to mid wala bhi bad hota
            low=mid+1;    
            
        }
        return low+1;
    }
};