class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1, bits = 32, result = 0;
        for (int i = 0; i < bits; ++i) {
            int mask = 1 << i;
            int expectedSetBits = 0, actualSetBits = 0;
            for (int num = 1; num < n + 1; ++num) {
                if (mask & num) {
                    expectedSetBits++;
                }
            }
            for (int i = 0; i < n + 1; ++i) {
                if (mask & nums[i]) {
                    actualSetBits++;
                }
            }
            if (actualSetBits > expectedSetBits) {
                result |= mask;
            }
        }
        return result;
    }
};