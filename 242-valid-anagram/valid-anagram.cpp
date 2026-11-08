class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> seenS, seenT;
        for (auto chr : s) {
            seenS[chr]++;
        }
        for (auto chr : t) {
            seenT[chr]++;
        }
        return seenS == seenT;
    }
};
