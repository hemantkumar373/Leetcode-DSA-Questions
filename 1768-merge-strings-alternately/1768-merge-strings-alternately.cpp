class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string res = "";

        for (int i = 0; i < min(m, n); i++) {
            res += word1[i];
            res += word2[i];
        }

        int i = min(m, n);
        while (i < m) {
            res += word1[i];
            i++;
        }

        while (i < n) {
            res += word2[i];
            i++;
        }
        return res;
    }
};