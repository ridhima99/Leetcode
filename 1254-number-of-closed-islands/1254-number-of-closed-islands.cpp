class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // Out of boundary
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        // Water ya already visited
        if (grid[i][j] == 1)
            return;

        // Mark visited
        grid[i][j] = 1;

        // Explore 4 directions
        dfs(grid, i - 1, j); // Up
        dfs(grid, i + 1, j); // Down
        dfs(grid, i, j - 1); // Left
        dfs(grid, i, j + 1); // Right
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // STEP 1 : Remove islands connected to LEFT & RIGHT boundary
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 0)
                dfs(grid, i, 0);

            if (grid[i][m - 1] == 0)
                dfs(grid, i, m - 1);
        }

        // STEP 2 : Remove islands connected to TOP & BOTTOM boundary
        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 0)
                dfs(grid, 0, j);

            if (grid[n - 1][j] == 0)
                dfs(grid, n - 1, j);
        }

        // STEP 3 : Count remaining closed islands
        int count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0) {

                    count++;

                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};