class Solution {
    char getBracket(char bracket) {
        switch (bracket) {
            case ')':
                return '(';
            case '}':
                return '{';
            case ']':
                return '[';
            default:
                return bracket;
        }
    }

public:
    bool isValid(string s) {
        stack<char> stk;
        for (char chr : s) {
            char bracket = getBracket(chr);
            if (bracket == chr) {
                stk.push(chr);
                continue;
            }
            // closed bracket confirmed.
            if (stk.empty()) {
                // no bracket was opened before.
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
