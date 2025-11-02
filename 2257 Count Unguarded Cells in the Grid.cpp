class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Create an empty grid
        // 0 = empty, 1 = wall, 2 = guard, 3 = guarded cell
        vector<vector<int>> grid(m, vector<int>(n, 0));

        //Mark walls as 1 and guards as 2
        for (auto &w : walls) grid[w[0]][w[1]] = 1;
        for (auto &g : guards) grid[g[0]][g[1]] = 2;

        // Define 4 directions → up, down, left, right
        int dr[4] = {-1, 1, 0, 0}; // row changes
        int dc[4] = {0, 0, -1, 1}; // column changes

        // From each guard, mark all visible cells
        for (auto &g : guards) {
            for (int d = 0; d < 4; d++) {
                int r = g[0] + dr[d];
                int c = g[1] + dc[d];

                // Keep moving in one direction until wall/guard/boundary
                while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 1 && grid[r][c] != 2) {
                    if (grid[r][c] == 0) grid[r][c] = 3; // mark as guarded
                    r += dr[d];
                    c += dc[d];
                }
            }
        }

        // Step 5️⃣: Count how many cells are still 0 (unguarded)
        int count = 0;
        for (auto &row : grid)
            for (int cell : row)
                if (cell == 0) count++;

        return count;
    }
};
