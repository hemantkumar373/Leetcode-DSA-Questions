class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp;
        for (auto it : magazine) {
            mpp[it]++;
        }
        for (auto it : ransomNote) {
            if (mpp.find(it) != mpp.end() && mpp[it] != 0) {
                mpp[it]--;
            } else {
                return false;
            }
        }
        return true;
    }
};