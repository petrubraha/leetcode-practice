class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxLen = 0, count = seen.size(), processed = 0;
        for (int num : seen) {
            if (seen.count(num - 1) != 0) {
                continue;
            }
            int len = 1;
            while (seen.count(++num) == 1) {
                len++;
            }
            maxLen = max(maxLen, len);
            processed += len;
            if (count - processed <= maxLen) {
                break;
            }
        }
        return maxLen;
    }
};