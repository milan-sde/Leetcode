class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        
        for (int num : nums) {
            int remainder = num % 3;
            if (remainder == 1 || remainder == 2) {
                operations++;
            }
            // If remainder is 0, no operations needed
        }
        
        return operations;
    }
};
