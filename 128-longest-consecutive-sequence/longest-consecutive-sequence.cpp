class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 0;
        unordered_map<int, int> numToLen;
        for (int num : nums) {
            if (numToLen[num] != 0) {
                continue;
            }
            int value = 1 + numToLen[num - 1] + numToLen[num + 1];
            numToLen[num] = value;
            numToLen[num - numToLen[num - 1]] = value;
            numToLen[num + numToLen[num + 1]] = value;
            len = max(len, value);
        }
        return len;
    }
};
