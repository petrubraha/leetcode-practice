class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> anagramToIndex;
        for (const string& str: strs) {
            string anagram(26, 0);
            for (char chr : str) {
                anagram[chr - 'a']++;
            }
            auto ans = anagramToIndex.try_emplace(anagram, result.size());
            if (ans.second) {
                result.emplace_back(1, str);
            } else {
                result[ans.first->second].push_back(str);
            }
        }
        return result;
    }
};