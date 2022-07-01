class Solution {
public:
    static bool cmp(vector<int> v1,vector<int> v2){
        return v1[1]>v2[1]; // sort in decreasing order of per box units
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        
        int res=0;
       for(int i=0;i<boxTypes.size();i++){
           
           if(boxTypes[i][0]<truckSize){ // no of box
               res+=boxTypes[i][1]*boxTypes[i][0];
               truckSize-=boxTypes[i][0];
           }
           else{
               if(truckSize!=0){
                   res+=truckSize*boxTypes[i][1];
                   break;
               }
           }
           
           
           
       }
       return res; 
    }
};