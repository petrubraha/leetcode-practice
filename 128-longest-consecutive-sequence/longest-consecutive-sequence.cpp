class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        numSet.reserve(n);
        for (int i = 0; i < n; ++i) {
            numSet.insert(nums[i]);
        }
        int maxLen = 0, setSize = numSet.size(), seen = 0;
        for (int num : numSet) {
            if (numSet.find(num - 1) != numSet.end()) {
                continue;
            }
            int len = 1, nxt = num + 1;
            while (numSet.find(nxt) != numSet.end()) {
                len++;
                nxt++;
            }
            maxLen = max(maxLen, len);
            seen += len;
            if (maxLen >= setSize - seen) {
                break;
            }
        }
        return maxLen;
    }
};