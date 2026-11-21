class Solution {
public:
    long long minimumSteps(string s) {
        long long n = s.size(), swaps = 0, counts = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                counts++;
            } else {
                swaps += counts;
            }
        }
        return swaps;
    }
};