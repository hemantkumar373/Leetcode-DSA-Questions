class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int cnt = 0, sum = 0;
        int even = 1, odd = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                cnt = (cnt + odd) % MOD;
                even++;
            } else {
                cnt = (cnt + even) % MOD;
                odd++;
            }
        }
        return cnt;
    }
};