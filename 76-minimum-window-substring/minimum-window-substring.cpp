class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) {
            return "";
        }
        unordered_map<char, unsigned short> sCounts, tCounts;
        sCounts.reserve(2 * 26);
        tCounts.reserve(2 * 26);
        for (char chr : t) {
            tCounts[chr]++;
        }
        int wL = 0, wR = m + 1;
        int have = 0, need = tCounts.size();
        int l = 0;
        for (int r = 0; r < m; ++r) {
            int sCount = ++sCounts[s[r]];
            if (auto tIt = tCounts.find(s[r]); tIt != tCounts.end() && sCount == tIt->second) {
                have++;
            }
            while (have == need) {
                // save the solution found.
                if (r - l < wR - wL) {
                    wL = l;
                    wR = r;
                }
                // try to shrink it.
                sCount = --sCounts[s[l]];
                if (auto tIt = tCounts.find(s[l]); tIt != tCounts.end() && sCount < tIt->second) {
                    have--;
                }
                l++;
            }
        }
        return wR == m + 1 ? "" : s.substr(wL, wR - wL + 1);
    }
};