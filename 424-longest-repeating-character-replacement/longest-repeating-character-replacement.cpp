class Solution {
    int getMaxFreq(int* seen) {
        int maxFreq = seen[0];
        for (int i = 1; i < 26; ++i) {
            maxFreq = max(maxFreq, seen[i]);
        }
        return maxFreq;
    }

public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int n = s.size(), l = 0, r = 0;
        int seen[256] = {};
        seen[s[0] - 'A']++;
        while (r < n) {
            int windowSize = r - l + 1;
            if (windowSize - getMaxFreq(seen) <= k) {
                maxLen = max(maxLen, windowSize);
                r++;
                if (r < n) {
                    seen[s[r] - 'A']++;
                }
            } else {
                seen[s[l] - 'A']--;
                l++;
            }
        }
        return maxLen;
    }
};