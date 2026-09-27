class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pairVector(n, -1);
        stack<int> pairStack;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                pairStack.push(i);
                continue;
            }

            if (s[i] == ')') {
                int match = pairStack.top();
                pairVector[i] = match;
                pairVector[match] = i;
                pairStack.pop();
            }
        }

        string result;
        for (int i = 0, direction = 1; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pairVector[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }

        return result;
    }
};