class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; ++i) {
            if (seen.find(nums[i] - 1) != seen.end()) {
                continue;
            }
            int len = 1, num = nums[i] + 1;
            while (seen.find(num) != seen.end()) {
                len++;
                num++;
            }
            maxLen = max(maxLen, len);
            if (maxLen >= n - i) {
                break;
            }
        }
        return maxLen;
    }
};