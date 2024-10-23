class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length() - 1;
        int openCnt = 0, closeCnt = 0;
        for(int i = 0; i <= n; i++){
            if(s[i] == '(' || s[i] == '*'){
                openCnt++;
            }
            else{
                openCnt--;
            }
            
            if(s[n - i] == ')' || s[n - i] == '*'){
                closeCnt++;
            }
            else{
                closeCnt--;
            }
            
            if(openCnt < 0 || closeCnt < 0) return false;
        }
        return true;
    }
};