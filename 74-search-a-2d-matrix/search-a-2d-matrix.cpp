class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int element = matrix[mid / n][mid % n];
            if (element == target) {
                return true;
            }
            if (element > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};