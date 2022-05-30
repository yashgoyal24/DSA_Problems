class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
   int min_till_now=INT_MAX; //keep track of minimum encountered till now
        int max_profit=INT_MIN;
     
        
        for(auto it:prices){
            
            min_till_now=min(min_till_now, it);
            
            max_profit=max(max_profit, it-min_till_now);
            
        }
        
        
        
        
        
     return max_profit;
    }
};