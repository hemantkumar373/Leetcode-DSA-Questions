class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        
        while(i < n){
            string temp = "";
            while(i < n && s[i] == ' ') i++;
            
            while(i < n && s[i] != ' '){
                temp += s[i];
                i++;
            }
            
            if(temp.size() > 0){
                if(ans.size() == 0){
                    ans = temp;
                }
                else{
                    ans = temp + ' ' + ans;
                }
            }
        }
        return ans;
    }
};