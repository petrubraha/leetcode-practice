class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> seen;
        seen.reserve(n);
        for (int i = 0; i < n; ++i) {
            auto it = seen.find(nums[i]);
            if (it == seen.end()) {
                seen[nums[i]] = i;
                continue;
            }
            if (nums[i] == nums[it->second] && i - it->second <= k) {
                return true;
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};