class Solution {
public:
    int trap(vector<int>& height) {
        
        
        //find left maximum and right maximum for all the elements
        
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        
        maxLeft[0]=height[0];
        maxRight[height.size()-1]=height[height.size()-1];
        
        for(int i=1;i<height.size();i++){
            maxLeft[i]=max(maxLeft[i-1],height[i]);
        }
        
        for(int i=height.size()-2;i>=0;--i){
            
                        
             maxRight[i]=max(maxRight[i+1],height[i]);

        }
        
        for(auto it:maxLeft){
            cout<< it<<"  ";
        }
        cout<<"Right";
        for(auto it:maxRight){
            cout<< it<<"  ";
        }
        
        
        int sum=0;
        vector<int> rain(height.size());
        for(int i=0;i<height.size();i++){
            
            rain[i]=min(maxLeft[i],maxRight[i])-height[i];
            sum+=rain[i];
        }
        return sum;
    }
    
};