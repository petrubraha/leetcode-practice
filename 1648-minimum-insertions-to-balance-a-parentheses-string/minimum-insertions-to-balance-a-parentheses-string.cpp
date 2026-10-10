class Solution {
public:
    int minInsertions(string s) {
        const int n = s.size();
        int owned = 0, fixes = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                owned += 2;
                if (owned & 1) {
                    owned -= 1;
                    fixes += 1;
                }
            } else {
                owned -= 1;
                if (owned < 0) {
                    owned += 2;
                    fixes += 1;
                }
            }
        }

        return fixes + owned;
    }
};