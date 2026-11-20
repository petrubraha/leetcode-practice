class Solution {
    bool isFreqEqual(int* freq1, int* freq2) {
        for (int i = 0; i < 26; ++i) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int s1N = s1.size(), s2N = s2.size();
        if (s1N > s2N) {
            return false;
        }
        int s1Freq[26] = {}, s2Freq[26] = {};
        for (int i = 0; i < s1N; ++i) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
        if (isFreqEqual(s1Freq, s2Freq)) {
            return true;
        }
        for (int l = 1; l + s1N <= s2N; ++l) {
            s2Freq[s2[l - 1] - 'a']--;
            s2Freq[s2[l + s1N - 1] - 'a']++;
            if (isFreqEqual(s1Freq, s2Freq)) {
                return true;
            }
        }
        return false;
    }
};