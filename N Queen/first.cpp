class Solution {
    bool safe(int row, int col, vector<string>&board, int n){
        int drow = row;
        int dcol = col;
        while(drow>=0 && dcol>=0){
            if(board[drow][dcol]=='Q')return false;
            drow--;
            dcol--;
        }

        drow = row;
        dcol = col;
        while(dcol>=0){
            if(board[drow][dcol]=='Q')return false;
            dcol--;
        }
        drow = row;
        dcol = col;
        while(drow<n && dcol >=0){
            if(board[drow][dcol]=='Q')return false;
            drow++;
            dcol--;
        }
        return true;
    }
    void recurse(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(safe(row, col, board, n)){
                board[row][col] = 'Q';
                recurse(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        recurse(0, board, ans, n);
        return ans;
    }
};