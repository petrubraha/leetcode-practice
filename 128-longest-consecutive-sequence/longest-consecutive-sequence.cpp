class Solution {
    int getCount(unordered_map<int, int>& numToCount, int value) {
        return numToCount.find(value) == numToCount.end() ? 0 : numToCount[value];
    }

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numToCount;
        numToCount.reserve(nums.size());
        int maxLen = 0;
        for (int num : nums) {
            if (numToCount.find(num) != numToCount.end()) {
                continue;
            }
            int prev = getCount(numToCount, num - 1), next = getCount(numToCount, num + 1);
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