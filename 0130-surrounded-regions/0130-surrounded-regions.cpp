class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, int n, int m) {
        // Boundary and check conditions
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O')
            return;
        
        // Mark this 'O' as safe (connected to border)
        board[i][j] = '#';
        
        // Move in all four directions
        dfs(i+1, j, board, n, m);
        dfs(i-1, j, board, n, m);
        dfs(i, j+1, board, n, m);
        dfs(i, j-1, board, n, m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        
        // Step 1: Run DFS from all border 'O's
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board, n, m);
            if (board[i][m-1] == 'O')
                dfs(i, m-1, board, n, m);
        }
        
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board, n, m);
            if (board[n-1][j] == 'O')
                dfs(n-1, j, board, n, m);
        }
        
        // Step 2: Flip all remaining 'O' to 'X' and '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};