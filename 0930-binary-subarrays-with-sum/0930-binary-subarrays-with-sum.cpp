class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, cnt = 0;
        if(goal < 0) return 0;
        
        while(r < n){
            sum += nums[r];
            while(l <= r && sum > goal){
                sum -= nums[l++];
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};