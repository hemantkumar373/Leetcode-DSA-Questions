class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long sum1N = (n * (n + 1)) / 2;
        long long sum2N = (n * (n + 1) * (2 * n + 1)) / 6;

        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums[i];
            sum2 += (long long)nums[i] * nums[i];
        }

        long long val1 = sum1 - sum1N;
        long long val2 = sum2 - sum2N;
        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};