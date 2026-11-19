class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> numbers, indexes;
        vector<int> result(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            while (!numbers.empty() && temperatures[i] >= numbers.top()) {
                numbers.pop();
                indexes.pop();
            }
            if (!numbers.empty()) {
                result[i] = indexes.top() - i;
            }
            numbers.push(temperatures[i]);
            indexes.push(i);
        }
        return result;
    }
};