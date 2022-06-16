class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        // border wale 0s ke components end me 0 rahenge
        // rest all 0s will be changed to X
        // So, find all Os in  border, using DFS uske component 0s ko 1 me badal denge
        
        
        for(int j=0;j<board[0].size();j++){
            
            if(board[0][j]=='O') // first row
                DFS(board,0,j);
            if(board[board.size()-1][j]=='O') // last row
                DFS(board,board.size()-1,j);
                
                
            
        }
        
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O') // first col
                DFS(board,i,0);
            if(board[i][board[0].size()-1]=='O') // last col
                DFS(board,i,board[0].size()-1);
        }
        
        // Now change O to X and -1 to O
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        
        
    }
    
    void DFS(vector<vector<char>>& grid,int i,int j){
        
        
          // check for overflow for i and j
        
        if(i>=0 && j>=0 && j<grid[0].size() && i<grid.size() && grid[i][j]=='O'){
            
            // 1 ko 0 banao, in short make it visited so that ispe vaapis naa aaye
            
            grid[i][j]='#';
            
            // make 4 calls now
            
            DFS(grid,i,j+1); // right
            DFS(grid,i,j-1); // left
            DFS(grid,i-1,j); // up
            DFS(grid,i+1,j); // down
            
            
            
            
        }
        
    }
};