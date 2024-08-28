class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        
        unordered_map<char,int> mpp;
        
        for(int i=0; i<n; i++){
            mpp[s[i]-'a']++;
            mpp[t[i]-'a']--;
        }
        
        for(auto i : mpp){
            if(i.second != 0) return false;
        }
        return true;
    }
};