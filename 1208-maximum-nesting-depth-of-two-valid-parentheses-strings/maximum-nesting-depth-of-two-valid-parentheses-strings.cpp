class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int n = seq.size();
        vector<int> result(n, 0);
        stack<bool> openBrackets;

        bool value = 0;
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                if (openBrackets.empty()) {
                    openBrackets.push(false);
                    // No write to result, initialized with 0.
                } else {
                    // Specific negation.
                    bool nextValue = !openBrackets.top();
                    openBrackets.push(nextValue);
                    // I hope this is a real optimization, evade the need to write to memory.
                    // I guess we can simply do result[i] = (int)nextValue;
                    if (nextValue) {
                        result[i] = 1;
                    }
                }
            } else {
                bool stackTop = openBrackets.top();
                openBrackets.pop();
                if (stackTop) {
                    result[i] = 1;
                }
            }
        }

        return result;
    }
};