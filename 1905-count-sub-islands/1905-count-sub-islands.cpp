class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2,
            int delrow[], int delcol[]) {
        int n = grid1.size();
        int m = grid1[0].size();

        grid2[row][col] = -1;
        bool isSubIsland = (grid1[row][col] == 1);

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid2[nrow][ncol] == 1) {
                isSubIsland &= dfs(nrow, ncol, grid1, grid2, delrow, delcol);
            }
        }
        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslands = 0;
        int n = grid2.size();
        int m = grid2[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (grid2[row][col] == 1 && dfs(row, col, grid1, grid2, delrow, delcol)) {
                    subIslands++;
                }
            }
        }
        return subIslands;
    }
};