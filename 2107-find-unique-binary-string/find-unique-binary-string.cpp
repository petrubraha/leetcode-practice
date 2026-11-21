class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string solution = nums[0];
        int bitIdx = 0;
        for (int i = 0; i < n; ++i) {
            bool foundDifferent = false;
            for (int j = 0; j < 1 + i; ++j) {
                if (solution[j] != nums[i][j]) {
                    foundDifferent = true;
                    break;
                }
            }
            if (!foundDifferent) {
                solution[i] = '1' - solution[i] + '0';
            }
        }
        return solution;
    }
};
