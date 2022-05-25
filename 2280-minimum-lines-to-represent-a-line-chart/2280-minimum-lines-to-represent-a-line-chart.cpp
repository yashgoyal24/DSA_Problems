class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        //first sort on the basis of day/X axis values
        
        sort(stockPrices.begin(),stockPrices.end());
        
        //If only 1 point
        
        int counter=0;
        
        if(stockPrices.size()==1)
            return counter;   //No line required
        
        else{   //More than 1 point, so atleast 1 line required 
            
            
            counter=1;
            
            for(int i=2;i<stockPrices.size();i++){   //size more than 2
                
                long x1=stockPrices[i-2][0],x2=stockPrices[i-1][0],x3=stockPrices[i][0];
                 long y1=stockPrices[i-2][1],y2=stockPrices[i-1][1],y3=stockPrices[i][1];
                
                long lhs=(y3-y2)*(x2-x1);
                long rhs=(y2-y1)*(x3-x2);
                
                if(lhs!=rhs){
                    counter++;
                }
            }
        }
        
        
        return counter;
    }
};