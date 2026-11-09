class Solution {
    void findSolution(vector<vector<int>>& sols, vector<int>& nums, int n, int i) {
        int l = i + 1, r = n - 1, target = -nums[i];
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum > target) {
                r--;
            } else if (sum < target) {
                l++;
            } else {
                // found solution;
                sols.push_back({nums[i], nums[l], nums[r]});
                l++, r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] > 0 || nums[n - 1] < 0) {
            return {};
        }
        vector<vector<int>> result;
        findSolution(result, nums, n, 0);
        for (int i = 1; i < n - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            findSolution(result, nums, n, i);
        }
        return result;
    }
};