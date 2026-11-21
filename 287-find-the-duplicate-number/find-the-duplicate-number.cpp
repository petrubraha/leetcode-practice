class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int bits = 32;
        int result = 0;
        for (int i = 0; i < bits; ++i) {
            int mask = 1 << i;
            int observed = 0, count = 0;
            for (int num = 1; num < n + 1; ++num) {
                if (mask & num) {
                    count++;
                }
            }
            for (int j = 0; j < n + 1; ++j) {
                if (mask & nums[j]) {
                    observed++;
                }
            }
            if (observed > count) {
                result |= mask;
            }
        }
        return result;
    }
};
