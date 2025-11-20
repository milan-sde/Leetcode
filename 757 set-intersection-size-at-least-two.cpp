class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Sort by end ascending, and start descending
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b){
                 if (a[1] == b[1])
                     return a[0] > b[0];
                 return a[1] < b[1];
             });

        int count = 0;
        int a = -1, b = -1;  // last two picked numbers

        for (auto &it : intervals) {
            int start = it[0], end = it[1];

            bool a_in = (a >= start);
            bool b_in = (b >= start);

            if (a_in && b_in) {
                continue; // already have 2 numbers in interval
            }
            else if (b_in) {
                // Only one number (b) is inside → pick one more
                count++;
                a = b;
                b = end;
            }
            else {
                // No numbers inside → pick two numbers
                count += 2;
                a = end - 1;
                b = end;
            }
        }

        return count;
    }
};
