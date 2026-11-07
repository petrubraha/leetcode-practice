class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int num1, num2;
        stack<int> stk;
        for (const string& tok : tokens) {
            char chr = tok[0];
            if (tok.size() > 1) {
                stk.push(stoi(tok));
                continue;
            }
            switch (chr) {
                case '+':
                    num1 = stk.top(); stk.pop();
                    num2 = stk.top(); stk.pop();
                    stk.push(num2 + num1);
                    break;
                case '-':
                    num1 = stk.top(); stk.pop();
                    num2 = stk.top(); stk.pop();
                    stk.push(num2 - num1);
                    break;
                case '*':
                    num1 = stk.top(); stk.pop();
                    num2 = stk.top(); stk.pop();
                    stk.push(num2 * num1);
                    break;
                case '/':
                    num1 = stk.top(); stk.pop();
                    num2 = stk.top(); stk.pop();
                    stk.push(num2 / num1);
                    break;
                default:
                    stk.push(stoi(tok));
                    break;
            }
        }
        return stk.top();
    }
};
