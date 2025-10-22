
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> originalCount;  // Counts how many times each number appears in the original array
        map<long long, int> changeMap;          // Used for sweep line: tracks how many elements can be changed to a certain value

        // Step 1: Fill both maps
        for (int num : nums) {
            originalCount[num]++;

            // This number can be changed to any value in the range [num - k, num + k]
            // So we increase at num - k and decrease after num + k
            changeMap[(long long)num - k] += 1;
            changeMap[(long long)num + k + 1] -= 1;
        }

        // Step 2: Make sure every number from the original list is included in the map
        // So we don’t skip checking its frequency
        for (auto& pair : originalCount) {
            int value = pair.first;
            if (!changeMap.count(value)) {
                changeMap[value] = 0;
            }
        }

        // Step 3: Sweep through values and track how many numbers can be changed to each value
        long long currentReachable = 0;
        int maxFrequency = 0;

        for (auto& entry : changeMap) {
            long long value = entry.first;
            int delta = entry.second;

            currentReachable += delta;  // Update how many numbers can be changed to this value

            int alreadyEqual = originalCount.count(value) ? originalCount[value] : 0;

            // We can only use 'numOperations' operations to convert elements
            // So maximum frequency we can reach for this value is:
            int possibleFrequency = min((long long)alreadyEqual + numOperations, currentReachable);

            maxFrequency = max(maxFrequency, possibleFrequency);
        }

        return maxFrequency;
    }
};
