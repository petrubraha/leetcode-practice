class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        map<array<char, 26>, int> anagramToIdx;
        result.reserve(n);
        for (const string& str : strs) {
            array<char, 26> anagram{};
            for (char chr : str) {
                anagram[chr - 'a']++;
            }
            auto pair = anagramToIdx.try_emplace(anagram, result.size());
            // if was just inserted, i.e. didn't exist before.
            if (pair.second) {
                result.emplace_back(1, str);
            } else {
                // get the iterator, and the value of the map, i.e. the index.
                result[pair.first->second].push_back(str);
            }
        }
        return result;
    }
};