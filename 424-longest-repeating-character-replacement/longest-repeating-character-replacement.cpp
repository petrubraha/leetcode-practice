class Solution {
    int getFreqMax(int* freq) {
        int freqMax = 0;
        for (int i = 0; i < 26; ++i) {
            freqMax = max(freqMax, freq[i]);
        }
        return freqMax;
    }

public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, sLen = s.size();
        int l = 0, r = 0;
        int freq[26] = {};
        freq[s[r] - 'A']++;
        while (r < sLen) {
            int wLen = r - l + 1;
            if (wLen - getFreqMax(freq) <= k) {
                maxLen = max(maxLen, wLen);
                if (++r == sLen) {
                    break;
                }
                freq[s[r] - 'A']++;
            } else {
                freq[s[l] - 'A']--;
                l++;
            }
        }
        return maxLen;
    }
};