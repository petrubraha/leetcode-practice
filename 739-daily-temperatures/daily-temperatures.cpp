class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> numbers, indexes;
        numbers.push(temperatures[n - 1]);
        indexes.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!numbers.empty() && temperatures[i] >= numbers.top()) {
                numbers.pop();
                indexes.pop();
            }
            if (!numbers.empty() && temperatures[i] < numbers.top()) {
                result[i] = indexes.top() - i;
            }
            numbers.push(temperatures[i]);
            indexes.push(i);
        }
        return result;        
    }
};