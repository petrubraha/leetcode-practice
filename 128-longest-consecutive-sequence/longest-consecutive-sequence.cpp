class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numToCount;
        int maxLen = 0;
        for (int num : nums) {
            if (numToCount[num] != 0) {
                continue;
            }
            int prev = numToCount[num - 1], next = numToCount[num + 1];
            int value = 1 + prev + next;
            numToCount[num] =
                numToCount[num - prev] =
                numToCount[num + next] =
                value;
            maxLen = max(maxLen, value);
        }
        return maxLen;
    }
};