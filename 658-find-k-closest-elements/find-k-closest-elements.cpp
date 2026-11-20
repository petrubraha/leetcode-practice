class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += abs(arr[i] - x);
        }
        int n = arr.size();
        int l = 0;
        for (int i = 1; i + k <= n; ++i) {
            int newSum = sum;
            newSum -= abs(arr[i - 1] - x);
            newSum += abs(arr[i + k - 1] - x);
            if (newSum > sum) {
                break;
            } else if (newSum < sum) {
                sum = newSum;
                l = i;
            }
        }
        vector<int> result(k, arr[l]);
        for (int i = 1; i < k; ++i) {
            result[i] = arr[l + i];
        }
        return result;
    }
};