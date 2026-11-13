class Solution {
    bool isOperation(string& str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for (string& tok : tokens) {
            if (!isOperation(tok)) {
                operands.push(stoi(tok));
                continue;
            }
            int last = operands.top(); operands.pop();
            int frst = operands.top(); operands.pop();
            if (tok == "+") {
                operands.push(frst + last);
            } else if (tok == "-") {
                operands.push(frst - last);
            } else if (tok == "*") {
                operands.push(frst * last);
            } else if (tok == "/") {
                operands.push(frst / last);
            }
        }
        return operands.top();
    }
};