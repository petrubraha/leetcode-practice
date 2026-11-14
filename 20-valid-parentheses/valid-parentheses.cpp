class Solution {
    char getBracketMatch(char bracket) {
        switch (bracket) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return bracket;
        }
    }

public:
    bool isValid(string s) {
        stack<int> stk;
        for (char chr : s) {
            char bracket = getBracketMatch(chr);
            if (chr == bracket) {
                stk.push(chr);
                continue;
            }
            // closed bracket.
            if (stk.empty()) {
                return false;
            }
            if (stk.top() != bracket) {
                return false;
            }
            stk.pop();
        }
        return stk.empty();
    }
};