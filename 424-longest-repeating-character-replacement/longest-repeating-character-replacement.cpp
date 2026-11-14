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
        int seen[26] = {};
        int n = s.size(), l = 0, r = 0, maxLen = 0;
        seen[s[r] - 'A']++;
        while (r < n) {
            int windowSize = r - l + 1, f = getMaxFreq(seen);
            if (windowSize - f <= k) {
                maxLen = max(maxLen, windowSize);
                if (++r != n) {
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
