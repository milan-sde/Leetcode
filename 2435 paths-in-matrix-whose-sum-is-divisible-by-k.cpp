class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][r] = number of paths to (i,j) with sum % k = r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        // Initialize starting position
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    if (i > 0) {
                        int new_r = (r + grid[i][j]) % k;
                        dp[i][j][new_r] = (dp[i][j][new_r] + dp[i-1][j][r]) % MOD;
                    }
                    if (j > 0) {
                        int new_r = (r + grid[i][j]) % k;
                        dp[i][j][new_r] = (dp[i][j][new_r] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }
        
        return dp[m-1][n-1][0] % MOD;
    }
};
