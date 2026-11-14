class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxLen = 0, l = 0;
        int seen[256] = {};
        for (int i = 0; i < n; ++i) {
            int index = seen[s[i]];
            if (index) {
                // not + 1, since we store 1-based indexes.
                l = max(l, index);
            }
            maxLen = max(maxLen, i + 1 - l);
            seen[s[i]] = i + 1;
        }
        return maxLen;
    }
};
