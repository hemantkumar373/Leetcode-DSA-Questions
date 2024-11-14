class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(int i = 0; i < columnTitle.size(); i++){
            res *= 26;
            res += (columnTitle[i] - 'A' + 1);
        }
        return res;
    }
};