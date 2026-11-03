class Solution {
public:
    void appendSolution(vector<vector<int>>& res, vector<int>& nums, int n, int i) {
        int l = i + 1, r = n - 1, target = -nums[i];
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                l++;
            } else if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                int lv = l, rv = r;
                while (l < r && nums[l] == nums[lv]) l++;
                while (l < r && nums[r] == nums[rv]) r--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[n - 1] < 0 || nums[0] > 0) {
            return {};
        }
        vector<vector<int>> res;
        appendSolution(res, nums, n, 0);
        for (int i = 1; i < n - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            appendSolution(res, nums, n, i);
        }
        return res;
    }
};
