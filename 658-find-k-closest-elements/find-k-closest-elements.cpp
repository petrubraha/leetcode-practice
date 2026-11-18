class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int sum = 0, bestL = 0;
        for (int i = 0; i < k; ++i) {
            sum += abs(x - arr[i]);
        }
        for (int i = 1; i < n - k + 1; ++i) {
            int newSum = sum - abs(x - arr[i - 1]) + abs(x - arr[i + k - 1]);
            if (newSum > sum) {
                break;
            }
            if (newSum == sum) {
                continue;
            }
            sum = newSum;
            bestL = i;
        }
        vector<int> result(k, arr[bestL]);
        for (int i = 0; i < k; ++i) {
            result[i] = arr[bestL + i];
        }
        return result;
    }
};