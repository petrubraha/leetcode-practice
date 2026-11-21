class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[l] == target) {
                return l;
            }
            if (nums[r] == target) {
                return r;
            }
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        r = n - 1;
        if (target == nums[l]) {
            return l;
        }
        if ((l > 0 && target > nums[l - 1]) || target < nums[l]) {
            return -1;
        }
        if (nums[r] < target) {
            r = l - 1;
            l = 0;
        }
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[l] == target) {
                return l;
            }
            if (nums[r] == target) {
                return r;
            }
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};
