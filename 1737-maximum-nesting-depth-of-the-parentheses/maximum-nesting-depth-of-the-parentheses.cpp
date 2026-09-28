class Solution {
public:
    int maxDepth(string s) {
        int count = 0, maxCount = 0;
        for (char character: s) {
            if (character == '(') {
                if (++count > maxCount) {
                    maxCount = count;
                }
            }
            if (character == ')') {
                --count;
            }
        }

        return maxCount;        
    }
};