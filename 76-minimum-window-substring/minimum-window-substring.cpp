class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) {
            return "";
        }
        unordered_map<char, int> tCounts;
        tCounts.reserve(2 * 26);
        for (char chr : t) {
            tCounts[chr]++;
        }
        int wL = 0, wR = m + 1;
        int needed = tCounts.size();
        for (int l = 0, r = 0; r < m; ++r) {
            if (auto tIt = tCounts.find(s[r]); tIt != tCounts.end() && --tIt->second == 0) {
                needed--;
            }
            while (needed == 0) {
                // save the solution found.
                if (r - l < wR - wL) {
                    wL = l;
                    wR = r;
                }
                // try to shrink it.
                if (auto tIt = tCounts.find(s[l]); tIt != tCounts.end() && ++tIt->second > 0) {
                    needed++;
                }
                l++;
            }
        }
        return wR == m + 1 ? "" : s.substr(wL, wR - wL + 1);
    }
};