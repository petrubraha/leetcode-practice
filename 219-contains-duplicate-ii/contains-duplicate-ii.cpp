class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }
        int n = nums.size();
        unordered_set<int> seen;
        seen.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (i > k) {
                seen.erase(nums[i - k - 1]);
            }
            if (seen.count(nums[i])) {
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};