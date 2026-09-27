class Solution {
public:
    string reverseString(string& s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string reverseSubstring(string& s, int n, int firstIndex, int& lastIndex) {
        string toReturn;
        for (int i = firstIndex; i < n; ++i) {
            if (s[i] == ')') {
                lastIndex = i;
                return reverseString(toReturn);
            }

            if (s[i] == '(') {
                int closingParanthesisIndex = -1;
                toReturn += reverseSubstring(s, n, i + 1, closingParanthesisIndex);
                i = closingParanthesisIndex;
                continue;
            }

            toReturn += s[i];
        }

        return toReturn;
    }

    string reverseParentheses(string s) {
        int dummy = 0;
        const int n = s.size();
        return reverseSubstring(s, n, 0, dummy);
    }
};