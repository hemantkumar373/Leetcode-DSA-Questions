class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for(int j = i; j < n; j++) {
                mpp[s[j]]++;
                
                int minCount = INT_MAX, maxCount = 0;
                for(auto it : mpp) {
                    minCount = min(minCount, it.second);
                    maxCount = max(maxCount, it.second);
                }
                sum += (maxCount - minCount);
            }
        }
        return sum;
    }
};