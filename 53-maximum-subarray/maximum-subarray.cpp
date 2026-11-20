class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = nums[0], bestSum = sum;
        for (int i = 1; i < n; ++i) {
            sum = max(nums[i], sum + nums[i]);
            bestSum = max(bestSum, sum);
        }
        return bestSum;
    }
};