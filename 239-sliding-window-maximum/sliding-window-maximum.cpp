class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        vector<int> leftMax(n, nums[0]), rghtMax(n, nums[n - 1]);
        for (int leftI = 1, rghtI = n - 2; leftI < n; ++leftI, --rghtI) {
            if (leftI % k == 0) {
                leftMax[leftI] = nums[leftI];
            } else {
                leftMax[leftI] = max(leftMax[leftI - 1], nums[leftI]);
            }
            if (rghtI % k == 0) {
                rghtMax[rghtI] = nums[rghtI];
            } else {
                rghtMax[rghtI] = max(rghtMax[rghtI + 1], nums[rghtI]);
            }
        }
        vector<int> result(n - k + 1, leftMax[0]);
        for (int i = 0; i < n - k + 1; ++i) {
            result[i] = max(rghtMax[i], leftMax[i + k - 1]);
        }
        return result;
    }
};