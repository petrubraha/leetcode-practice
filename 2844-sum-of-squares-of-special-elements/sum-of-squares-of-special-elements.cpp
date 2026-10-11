class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            const int num = nums[i];
            if (n % (i + 1) == 0) {
                ans += num * num;
            }
        }
        return ans;
    }
};