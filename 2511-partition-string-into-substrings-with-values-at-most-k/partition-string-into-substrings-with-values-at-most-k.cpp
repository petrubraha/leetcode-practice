class Solution {
public:
    int minimumPartition(string s, int k) {
        int result = 0;
        long long num = 0;
        for (char c : s) {
            long long digit = c - '0';
            if (digit > k) {
                return -1;
            }
            if (num * 10 + digit > k) {
                result++;
                num = 0;
            }
            num = num * 10 + digit;
        }
        result += num > k ? 2 : 1;
        return result;        
    }
};