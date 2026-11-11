class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maximum = prices[n - 1], result = 0;
        for (int i = n - 2; i >= 0; --i) {
            maximum = max(maximum, prices[i + 1]);
            result = max(result, maximum - prices[i]);
        }
        return result;
    }
};
