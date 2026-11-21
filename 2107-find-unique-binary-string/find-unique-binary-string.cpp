class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string solution = nums[0];
        for (int i = 0; i < n; ++i) {
            solution[i] = '1' - nums[i][i] + '0';
        }
        return solution;
    }
};
