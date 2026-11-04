class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j; ) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i+1, j+1};
            }
            if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1};
    }
};