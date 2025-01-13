class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, int& area, int delrow[], int delcol[]) {
        int n = grid.size();
        int m = grid[0].size();

        area++;
        grid[row][col] = 0;

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, area, delrow, delcol);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        int maxArea = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int area = 0;
                if (grid[row][col] == 1) {
                    dfs(row, col, grid, area, delrow, delcol);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};