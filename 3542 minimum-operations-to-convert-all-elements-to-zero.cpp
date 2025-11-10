class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int operations = 0;

        for(int i=0;i<nums.size(); i++){
            while(!s.empty() && s.top() > nums[i]){
                s.pop();
            }

            if(nums[i] == 0){
                continue;
            }

            if(s.empty() || s.top() < nums[i]){
                s.push(nums[i]);
                operations++;
            }
        }

        return operations;
    }
};  
