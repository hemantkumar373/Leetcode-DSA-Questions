class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        
        vector<int> mpp(26,0);
        
        for(int i=0; i<n; i++){
            mpp[s[i]-'a']++;
            mpp[t[i]-'a']--;
        }
        
        for(auto it : mpp){
            if(it != 0) return false;
        }
        return true;
    }
};