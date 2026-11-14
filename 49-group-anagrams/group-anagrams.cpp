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
            auto it = anagramToIndex.find(anagram);
            if (it != anagramToIndex.end()) {
                result[it->second].push_back(str);
            } else {
                anagramToIndex[anagram] = result.size();
                result.emplace_back(1, str);
            }
        }
        return result;
    }
};