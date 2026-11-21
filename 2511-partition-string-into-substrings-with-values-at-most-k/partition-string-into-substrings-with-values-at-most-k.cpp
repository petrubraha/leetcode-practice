class Solution {
public:
    int minimumPartition(string s, int k) {
        int count = 0;
        long long num = 0;
        for (char c : s) {
            int digit = c - '0';
            if (digit > k) {
                return -1;
            }
            if (num * 10 + digit > k) {
                count++;
                num = 0;
            }
            num *= 10;
            num += digit;
        }
        return count + 1;
    }
};