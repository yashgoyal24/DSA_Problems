class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n=piles.size();
        int low=1; // minimum speed to eat bananas
        int high=piles[n-1]; // maxium speed to eat bananas
        int result=-1;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(isPossible(piles,n,h,mid)){
                // possible in speed=mid, so go to left to minimize
                high=mid-1;
                result=mid; // need to keep updating this
            }
            else
                // not possible in mid speed, so increase speed
                low=mid+1;
            
        }
        
        return result;
    }
    
    bool isPossible(vector<int> piles, int n, int h, int speed){
        
        int hours=0;
        for(int i=0;i<n;i++){
            if(piles[i]<=speed)
                hours++;
            else{
                int h;
                if(piles[i]%speed==0)
                    h=piles[i]/speed;
                else
                h=piles[i]/speed + 1; // takr ceil of the value
                hours+=h;
            }
            if(hours>h)
                return false;
        }
        
        return true;
        
        
    }
};