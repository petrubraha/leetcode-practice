class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        size_t n = s.size(), startIdx = s.find(goal[0]);
        
        while (startIdx != string::npos) {
            bool result = true;
            for (int i = 1; i < n; ++i) {
                if (s[(startIdx + i) % n] != goal[i]) {
                    result = false;
                    break;
                }
            }

            if (result) {
                return true;
            }
            startIdx = s.find(goal[0], startIdx + 1);
        }

        return false;
    }
};