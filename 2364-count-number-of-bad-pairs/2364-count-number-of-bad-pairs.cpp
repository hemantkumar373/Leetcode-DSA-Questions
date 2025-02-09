class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> mpp;
        long long n = nums.size();
        long long totalPairs = n * (n - 1) / 2;
        long long goodPairs = 0;

        for (long long i = 0; i < n; i++) {
            goodPairs += mpp[i - nums[i]];
            mpp[i - nums[i]]++;
        }

        return totalPairs - goodPairs;
    }
};