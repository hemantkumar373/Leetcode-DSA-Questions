class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        priority_queue<pair<int, char>> pq;
        string ans = "";
        
        for(char &ch : s) {
            mpp[ch]++;
        }
        
        for(auto &it : mpp) {
            pq.push({it.second, it.first});
        }
        
        while(!pq.empty()) {
            auto it = pq.top();
            ans += string(it.first, it.second);
            pq.pop();
        }
        return ans;
    }
};