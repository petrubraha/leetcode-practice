class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 1;
        for (int i = 0; i < n; ++i) {
            r = max(r, piles[i]);
        }
        int minK = r;
        while (l <= r) {
            int k = (l + r) / 2;
            long long need = 0;
            for (int i = 0; i < n; ++i) {
                bool hasRest = piles[i] % k > 0;
                need += piles[i] / k + hasRest;
            }
            if (need <= h) {
                minK = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return minK;
    }
};
