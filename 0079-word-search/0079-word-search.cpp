class Solution {
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(int idx, int row, int col, vector<vector<char>>& board, string& word) {
        if (idx == l)
            return true;
        if (row < 0 || row == n || col < 0 || col == m || board[row][col] != word[idx]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '$';

        for (auto& dir : directions) {
            int nrow = row + dir[0];
            int ncol = col + dir[1];

            if (find(idx + 1, nrow, ncol, board, word))
                return true;
        }

        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        l = word.length();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(0, i, j, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};