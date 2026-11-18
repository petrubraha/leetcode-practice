class Solution {
public:
    string minWindow(string s, string t) {
        int sN = s.size(), tN = t.size();
        unordered_map<char, int> tCounts;
        tCounts.reserve(tN);
        for (char chr : t) {
            tCounts[chr]++;
        }
        unordered_map<char, int> wCounts;
        wCounts.reserve(tN);
        int lMin = 0, lenMin = INT_MAX;
        int have = 0, need = tCounts.size();
        int l = 0;
        for (int r = 0; r < sN; ++r) {
            char chr = s[r];
            auto it = tCounts.find(chr);
            int wChrCount = ++wCounts[chr];
            if (it != tCounts.end() && wChrCount == it->second) {
                have++;
            }
            while (have == need) {
                // we found a valid substring, save it.
                int size = r - l + 1;
                if (size < lenMin) {
                    lenMin = size;
                    lMin = l;
                }
                // shrink the substring if possible.
                char chracter = s[l];
                auto it = tCounts.find(chracter);
                int wChrNewCount = --wCounts[chracter];
                if (it != tCounts.end() && wChrNewCount < it->second) {
                    have--;
                }
                l++;
            }
        }
        return lenMin == INT_MAX ? "" : s.substr(lMin, lenMin);
    }
};
