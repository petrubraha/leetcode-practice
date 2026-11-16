class Solution {
    bool isFreqEqual(short* freqS1, short* freqS2) {
        for (int i = 0; i < 26; ++i) {
            if (freqS1[i] != freqS2[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int nS1 = s1.size(), nS2 = s2.size();
        if (nS1 > nS2) {
            return false;
        }
        short freqS1[26] = {}, freqS2[26] = {};
        for (int i = 0; i < nS1; ++i) {
            freqS1[s1[i] - 'a']++;
            freqS2[s2[i] - 'a']++;
        }
        if (isFreqEqual(freqS1, freqS2)) {
            return true;
        }
        for (int l = 1; l + nS1 <= nS2; ++l) {
            freqS2[s2[l - 1] - 'a']--;
            freqS2[s2[l - 1 + nS1] - 'a']++;
            if (isFreqEqual(freqS1, freqS2)) {
                return true;
            }
        }
        return false;
    }
};