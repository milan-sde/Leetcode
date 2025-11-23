class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[0], dp[1], dp[2] represent max sum with remainder 0, 1, 2
        vector<int> dp = {0, INT_MIN, INT_MIN};
        
        for (int num : nums) {
            // Create a copy of current dp state
            vector<int> temp = dp;
            
            for (int i = 0; i < 3; i++) {
                if (temp[i] != INT_MIN) {
                    // Calculate new remainder when adding current number
                    int new_remainder = (temp[i] + num) % 3;
                    // Update dp with maximum value for the new remainder
                    dp[new_remainder] = max(dp[new_remainder], temp[i] + num);
                }
            }
        }
        
        return dp[0];
    }
};  
