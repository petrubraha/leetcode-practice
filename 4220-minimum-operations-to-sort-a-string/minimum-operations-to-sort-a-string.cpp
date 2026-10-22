class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool isSorted = true;

        char prev = s[0], mn = prev, mx = prev;
        for (int i = 1; i < n; ++i) {
            char chr = s[i];
            mn = min(mn, chr);
            mx = max(mx, chr);
            if (chr < prev) {
                isSorted = false;
            }
            prev = chr;
        }

        if (isSorted == true) {
            return 0;
        }
        if (n == 2) {
            return -1;
        }

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        return 3;
    }
};