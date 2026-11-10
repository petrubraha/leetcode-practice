class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> numbers, indexes;
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!numbers.empty() && temperatures[i] > numbers.top()) {
                int topIndex = indexes.top(); 
                numbers.pop();
                indexes.pop();
                result[topIndex] = i - topIndex;
            }
            if (numbers.empty() || temperatures[i] <= numbers.top()) {
                numbers.push(temperatures[i]);
                indexes.push(i);
            }
        }
        return result;
    }
};