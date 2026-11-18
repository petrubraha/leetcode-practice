class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, sum = 0;
        int minLen = INT_MAX;
        while (r < n) {
            sum += nums[r];
            while (sum >= target && l <= r) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? 0 : minLen;        
    }
};