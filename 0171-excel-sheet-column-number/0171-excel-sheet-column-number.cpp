class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(char ch : columnTitle){
            res = res * 26 + (ch - 'A' + 1);
        }
        return res;
    }
};