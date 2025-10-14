// 3349 . Adjacent Increasing Subarrays Detection I

// Approach 1 : Brute Force
class Solution {
public:

    bool isIncreasing(vector<int>& nums, int s , int e){
        for(int i=s+1 ; i < e ; i++){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int s = 0 ; s + 2*k <= n ; s++){
            bool first = isIncreasing(nums, s , s + k);
            bool second = isIncreasing(nums, s+k, s + 2*k);

            if(first && second){
                return true;
            }
        }

        return false;
    }
};


