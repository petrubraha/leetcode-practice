class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxLen = 0, l = 0;
        unordered_map<char, int> seen;
        string buffer;
        buffer.reserve(n);
        for (int i = 0; i < n; ++i) {
            auto it = seen.find(s[i]);
            // the found element can be outside of the window, between [0, l).
            if (it != seen.end()) {
                l = max(l, it->second + 1);
            }
            buffer += s[i];
            maxLen = max(maxLen, (int)buffer.size() - l);
            seen[s[i]] = i;
        }
        return maxLen;
    }
};
