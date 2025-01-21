class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int l = 0, r = 0, cnt = 0;
        int minlen = INT_MAX, sIndex = -1;

        unordered_map<char, int> mpp;
        for (auto& ch : t) {
            mpp[ch]++;
        }

        while (r < n) {
            if (mpp[s[r]] > 0)
                cnt++;
            mpp[s[r]]--;

            while (cnt == m) {
                if (minlen > r - l + 1) {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};