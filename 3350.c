// 3350.Adjacent Increasing Subarrays Detection II - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

int maxIncreasingSubarrays(int* nums, int numsSize) {
    int prevRun = 0;
    int currRun = 1;
    int K = 0;

    for(int i=1;i<numsSize;i++){
        if(nums[i] > nums[i-1]){
            currRun++;
        }
        else{
            prevRun = currRun;
            currRun = 1;
        }

        if(currRun/2 > K){
            K = currRun / 2;
        }

        int minK = 0;
        minK = prevRun < currRun ? prevRun : currRun;
        K = K > minK ? K : minK;
    }
        return K;
}
