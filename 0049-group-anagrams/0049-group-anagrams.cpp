class Solution {
public:
    string generate(string& s){
        int cnt[26] = {0};
        
        for(char& ch : s){
            cnt[ch-'a']++;
        }
        
        string new_s;
        for(int i=0; i<26; i++){
            if(cnt[i] > 0){
                new_s += string(cnt[i],i+'a');
            }
        }
        return new_s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        
        for(string& s : strs){
            string new_s = generate(s);
            mpp[new_s].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto it : mpp){
            result.push_back(it.second);
        }
        return result;
    }
};