class Solution {
public:
    void appendSolution(vector<vector<int>>& result, vector<int>& nums, int n, int i) {
        int l = i + 1, r = n - 1, target = -nums[i];
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum > target) {
                r--;
            } else if (sum < target) {
                l++;
            } else {
                result.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[n - 1] < 0) {
            return {};
        }
        vector<vector<int>> result;
        appendSolution(result, nums, n, 0);

        for (int i = 1; i < n; ++i) {
            // if the smallest element of triplet is greater than 0
            // then all are greater than 0.
            if (nums[i] > 0) {
                break;
            }
            // starts from i = 1;
            // deletes the check: i > 0;
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            appendSolution(result, nums, n, i);
        }
        return result;
    }
};
