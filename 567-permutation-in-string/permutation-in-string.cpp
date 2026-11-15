class Solution {
    bool isFreqEqual(int* s1Freq, int* s2Freq) {
        for (int i = 0; i < 26; ++i) {
            if (s1Freq[i] != s2Freq[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int s1N = s1.size();
        int s2N = s2.size();
        if (s1N > s2N) {
            return false;
        }
        int s1Freq[26] = {};
        int s2Freq[26] = {};
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
