class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.size(), l = 0, r = 0;
        int seen[256] = {};
        while (r < n) {
            int duplicateIndex = seen[s[r]];
            if (duplicateIndex > l) {
                l = duplicateIndex;
            }
            maxLen = max(maxLen, r - l + 1);
            seen[s[r]] = r + 1;
            r++;
        }
        return maxLen;
    }
};