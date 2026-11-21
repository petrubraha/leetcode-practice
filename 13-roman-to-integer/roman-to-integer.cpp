class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values;
        values.reserve(7);
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;
        int n = s.size(), maxValue = values[s[n - 1]], result = maxValue;
        for (int i = n - 2; i >= 0; --i) {
            if (values[s[i]] >= maxValue) {
                result += values[s[i]];
                maxValue = values[s[i]];
            } else {
                result -= values[s[i]];
            }
        }
        return result;
    }
};