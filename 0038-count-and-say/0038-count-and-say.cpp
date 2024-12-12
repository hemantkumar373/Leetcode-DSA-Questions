class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string say = countAndSay(n - 1);
        
        string res = "";
        
        for(int i = 0; i < say.length(); i++) {
            char ch = say[i];
            int cnt = 1;
            
            while(i < say.length()-1 && say[i] == say[i+1]) {
                cnt++;
                i++;
            }
            
            res += to_string(cnt) + ch;
        }
        return res;
    }
};