class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, sum = 0;
        int minLen = n + 1;
        while (r < n) {
            sum += nums[r];
            while (sum >= target && l <= r) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLen == n + 1 ? 0 : minLen;
    }
};