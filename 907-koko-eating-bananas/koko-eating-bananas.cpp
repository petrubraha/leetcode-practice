class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), l = 1, r = piles[0];
        for (int i = 1; i < n; ++i) {
            r = max(r, piles[i]);
        }
        int minK;
        while (l <= r) {
            int k = (l + r) / 2;
            long long hours = 0;
            for (int i = 0; i < n; ++i) {
                bool carry = piles[i] % k;
                hours += piles[i] / k + carry;
            }
            if (hours > h) {
                l = k + 1;
            } else {
                minK = k;
                r = k - 1;
            }
        }
        return minK;
    }
};