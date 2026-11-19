class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maximum = prices[n - 1], result = 0;
        for (int i = n - 2; i >= 0; --i) {
            result = max(result, maximum - prices[i]);
            maximum = max(maximum, prices[i]);
        }
        return result;
    }
};