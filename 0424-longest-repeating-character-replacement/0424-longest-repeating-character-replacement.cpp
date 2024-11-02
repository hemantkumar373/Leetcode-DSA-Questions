class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxlen = 0, maxf = 0;
        int hash[26] = {0};
        
        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            
            if((r - l + 1) - maxf > k){
                hash[s[l] - 'A']--;
                l++;
            }
            
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};