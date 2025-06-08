class Solution {
    void recurse(int col, vector<string>& board, vector<vector<string>>& ans,
                 int n, vector<int>& leftRow, vector<int>& upperDia,
                 vector<int>& lowerDia) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDia[row + col] == 0 &&
                upperDia[n - 1 + col - row] == 0  ) {
                    board[row][col] = 'Q';
                    leftRow[row] = 1;
                    lowerDia[col + row] = 1;
                    upperDia[n - 1 + col - row] = 1;
                    recurse(col + 1, board, ans, n, leftRow, upperDia, lowerDia);
                    board[row][col] = '.';
                    upperDia[n - 1 + col - row] = 0;
                    lowerDia[col + row] = 0;
                    leftRow[row] = 0;
                }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftRow(n, 0);
        vector<int> upperDia(2 * n - 1, 0);
        vector<int> lowerDia(2 * n - 1, 0);
        recurse(0, board, ans, n, leftRow, upperDia, lowerDia);
        return ans;
    }
};