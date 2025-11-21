class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1); // first occurrence of each character
        vector<int> last(26, -1);  // last occurrence of each character
        
        // Find first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }
        
        int result = 0;
        
        // For each character that can be the outer characters
        for (int i = 0; i < 26; i++) {
            // If character appears at least twice (to form outer characters)
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) {
                // Count unique characters between first and last occurrence
                unordered_set<char> middleChars;
                
                for (int j = first[i] + 1; j < last[i]; j++) {
                    middleChars.insert(s[j]);
                }
                
                result += middleChars.size();
            }
        }
        
        return result;
    }
};
