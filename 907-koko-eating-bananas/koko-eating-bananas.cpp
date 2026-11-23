class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), l = 1, r = 0;
        for (int i = 0; i < n; ++i) {
            r = max(r, piles[i]);
        }
        int result = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long a = 0;
            for (int i = 0; i < n; ++i) {
                a = a + piles[i] / m + ((piles[i] % m) > 0 ? 1 : 0);
            }
            if (a > h) {
                l = m + 1;
            } else {
                result = m;
                r = m - 1;
            }
        }
        return result;
    }
};