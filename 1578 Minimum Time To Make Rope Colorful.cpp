

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int result = 0;
        int prevMax = 0;

        for (int i = 0; i < n; i++) {
            int curr = neededTime[i];
            if (i > 0 && colors[i] != colors[i - 1]) {
                prevMax = 0;
            }

            result += min(prevMax, curr);
            prevMax = max(prevMax, curr);
        }

        return result;
    }
};
