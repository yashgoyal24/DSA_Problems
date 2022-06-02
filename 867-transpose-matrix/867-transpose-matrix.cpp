class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
      int m=matrix.size();  // rows
    int n=matrix[0].size();  // columns
        
        vector<vector<int>> trans(n);
        for(int i=0;i<n;i++){
            vector<int> temp(m);
            for(int j=0;j<m;j++){
                temp[j]=matrix[j][i];
            }
            trans[i]=temp;
        }
        return trans;
    }
};