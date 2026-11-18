class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        vector<int> prefix(n, nums[n - 1]), suffix(n, nums[0]);
        for (int i = 1; i < n; ++i) {
            if ((n - 1 - i) % k == 0) {
                prefix[n - 1 - i] = nums[n - 1 - i];
            } else {
                prefix[n - 1 - i] = max(nums[n - 1 - i], prefix[n - i]);
            }
            if (i % k == 0) {
                suffix[i] = nums[i];
            } else {
                suffix[i] = max(nums[i], suffix[i - 1]);
            }
        }
        vector<int> result(n - k + 1, nums[0]);
        for (int i = 0; i < n - k + 1; ++i) {
            result[i] = max(prefix[i], suffix[i + k - 1]);
        }
        return result;
    }
};
