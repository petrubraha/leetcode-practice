class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        unsigned int copy = x, palindrome = 0;
        while (copy) {
            palindrome *= 10;
            palindrome += copy % 10;
            copy /= 10;
        }
        return x == palindrome;
    }
};