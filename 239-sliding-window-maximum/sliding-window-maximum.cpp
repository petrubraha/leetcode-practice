class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        vector<int> maxLeft(n, nums[0]), maxRght(n, nums[n - 1]);
        for (int i = 1; i < n; ++i) {
            if (i % k == 0) {
                maxLeft[i] = nums[i];
            } else {
                maxLeft[i] = max(maxLeft[i - 1], nums[i]);
            }
            if ((n - 1 - i) % k == 0) {
                maxRght[n - 1 - i] = nums[n - 1 - i];
            } else {
                maxRght[n - 1 - i] = max(maxRght[n - i], nums[n - i - 1]);
            }
        }
        vector<int> result;
        result.reserve(n - k + 1);
        for (int i = 0; i < n - k + 1; ++i) {
            result.push_back(max(maxLeft[i + k - 1], maxRght[i]));
        }
        return result;
    }
};