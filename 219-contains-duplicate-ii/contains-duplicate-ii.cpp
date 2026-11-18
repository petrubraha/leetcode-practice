class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }
        int n = nums.size();
        unordered_map<int, int> seen;
        seen.reserve(n);
        for (int i = 0; i < n; ++i) {
            auto result = seen.try_emplace(nums[i], i);
            if (!result.second) {
                if (i - result.first->second <= k) {
                    return true;
                }
                result.first->second = i;
            }
        }
        return false;
    }
};