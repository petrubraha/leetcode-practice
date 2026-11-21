class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        size_t n = 1, u = x;
        while (n * 10 <= u) {
            n *= 10;
        }
        while (u) {
            size_t first = u / n, last = u % 10;
            if (first != last) return false;
            u -= first * n;
            u /= 10;
            n /= 100;
        }
        return true;
    }
};
