class NumMatrix {
public:
    
vector<vector<int>> matrix1;
    NumMatrix(vector<vector<int>>& matrix) {
        
        // Store running sum over here
        
        for(int i=0;i<matrix.size();i++){
            
            int sum=0;
            vector<int> matRow;
            
            for(int j=0;j<matrix[i].size();j++){
                
                sum+=matrix[i][j];
                matRow.push_back(sum);
                
            }
            matrix1.push_back(matRow);
            for(auto it:matRow){
            cout<<it;
        }
        }
        
        
    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      
        int sum=0;
      
        for(int i=row1;i<=row2;i++){
           if(col1==col2 && col1==0){
               sum+=matrix1[i][0];
           }
            else if(col1==col2)
                sum+=(matrix1[i][col1]-matrix1[i][col1-1]);
            else{
                if(col1!=0)
           sum=sum+(matrix1[i][col2]-matrix1[i][col1-1]);
else
    sum=sum+(matrix1[i][col2]);

            }
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */