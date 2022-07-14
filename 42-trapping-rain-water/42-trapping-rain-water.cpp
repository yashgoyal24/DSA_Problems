class Solution {
public:
    int trap(vector<int>& height) {
        
        // find left max and right max for all elements
        
        //left max 
        
        int n=height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        int result=0;
        for(int i=1;i<n;i++){
            
            leftMax[i]=max(height[i], leftMax[i-1]);
           
        }
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        
        for(int i=0;i<n;i++){
            result+=(min(rightMax[i], leftMax[i])-height[i]);
        }
        
        
        return result;
    }
};