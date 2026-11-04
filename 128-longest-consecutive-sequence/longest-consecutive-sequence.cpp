class Solution {
    int getCount(unordered_map<int, int>& numToCount, int value) {
        return numToCount.find(value) == numToCount.end() ? 0 : numToCount[value];
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet(n);
        for (int i = 0; i < n; ++i) {
            numSet.insert(nums[i]);
        }
        int maxLen = 0, setSize = numSet.size();
        for (int num : numSet) {
            if (numSet.find(num - 1) != numSet.end()) {
                continue;
            }
            int len = 1, nxt = num + 1;
            while (numSet.find(nxt++) != numSet.end()) {
                len++;
            }
            maxLen = max(maxLen, len);
            if (maxLen == setSize) {
                break;
            }
        }
        return maxLen;
    }
};