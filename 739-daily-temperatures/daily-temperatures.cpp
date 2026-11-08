class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> numbers, indexes;
        for (int i = 0; i < n; ++i) {
            while (!numbers.empty() && temperatures[i] > numbers.top()) {
                int idx = indexes.top();
                numbers.pop();
                indexes.pop();
                result[idx] = i - idx;
            }
            numbers.push(temperatures[i]);
            indexes.push(i);
        }
        return result;
    }
};
