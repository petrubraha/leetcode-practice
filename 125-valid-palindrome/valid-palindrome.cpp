class Solution {
public:
    bool isAlphanumeric(char c) {
        return
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int n = s.size();
        for (int frst = 0, last = n - 1; frst < last; ++frst, --last) {
            while(frst < last && !isAlphanumeric(s[frst])) frst++; 
            while(frst < last && !isAlphanumeric(s[last])) last--; 
            if (tolower(s[frst]) != tolower(s[last])) {
                return false;
            }
        }
        return true;
    }
};
