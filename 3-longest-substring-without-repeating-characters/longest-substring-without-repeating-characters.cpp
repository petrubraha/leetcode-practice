class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int chrToIdx[256] = {};
        while (r < n) {
            if (chrToIdx[s[r]] > l) {
                l = chrToIdx[s[r]];
            }
            chrToIdx[s[r]] = r + 1;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};