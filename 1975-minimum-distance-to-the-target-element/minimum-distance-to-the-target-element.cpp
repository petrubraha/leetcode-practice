class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int prevIdx = start - i,
                nextIdx = start + i;
            
            if (prevIdx >= 0 && nums[prevIdx] == target) {
                return i;
            }

            if (nextIdx < n && nums[nextIdx] == target) {
                return i;
            }
        }

        return -1;
    }
};