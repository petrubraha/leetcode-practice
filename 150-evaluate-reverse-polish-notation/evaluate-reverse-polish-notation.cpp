class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size(), last, frst;
        for (int i = 0; i < n; ++i) {
            string& str = tokens[i];
            if (str.size() > 1) {
                stk.push((stoi(str)));
                continue;
            }
            char chr = str[0];
            switch (chr) {
                case '+':
                    last = stk.top(); stk.pop();
                    frst = stk.top(); stk.pop();
                    stk.push(frst + last);
                    break;
                case '-':
                    last = stk.top(); stk.pop();
                    frst = stk.top(); stk.pop();
                    stk.push(frst - last);
                    break;
                case '*':
                    last = stk.top(); stk.pop();
                    frst = stk.top(); stk.pop();
                    stk.push(frst * last);
                    break;
                case '/':
                    last = stk.top(); stk.pop();
                    frst = stk.top(); stk.pop();
                    stk.push(frst / last);
                    break;
                default:
                    stk.push((stoi(str)));
                    break;
            }
        }
        return stk.top();
    }
};