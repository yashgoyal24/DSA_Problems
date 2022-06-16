class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
         
        // DFS problem, starting at first letter of the word
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]==word[0]){ // first letter, so start DFS
                 
                    if(DFS(board,word,i,j,0)==true)
                        return true;
                    
                }
                
                
            }
            
            
        }
        
        
        
       return false; 
    }
    
    bool DFS(vector<vector<char>>& grid,string word,int i,int j,int current_index){
        
        if(current_index==word.size())
            return true;
        
         // check for overflow for i and j
        
        
        if(i<0 || j<0 || j>=grid[0].size() || i>=grid.size() || grid[i][j]!=word[current_index])
            return false;

            char temp=grid[i][j];
            grid[i][j]='*';
            
            // make 4 calls now
            
          bool bool_val=(DFS(grid,word,i,j+1,current_index+1) ||
            DFS(grid,word,i,j-1,current_index+1) ||
            DFS(grid,word,i-1,j,current_index+1) ||
            DFS(grid,word,i+1,j,current_index+1));
        
        
        
        
        
    grid[i][j]=temp;
 return bool_val;
    }
    
    
};