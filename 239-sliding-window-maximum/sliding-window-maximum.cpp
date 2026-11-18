class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        map<int, int> ordered;
        for (int i = 0; i < k - 1; ++i) {
            ordered[nums[i]]++;
        }
        int n = nums.size();
        vector<int> result(n - k + 1, nums[0]);
        for (int i = 0; i < n - k + 1; ++i) {
            int num = nums[i + k - 1];
            ordered[num]++;
            result[i] = prev(ordered.end())->first;
            if (--ordered[nums[i]] == 0) {
                ordered.erase(nums[i]);
            }
        }
        return result;
    }
};
