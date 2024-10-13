class Solution {
private:
    int countNum(vector<int>& nums, int k){
        int left = 0, right = 0;
        int odd = 0, cnt = 0;
        if(k < 0) return 0;
        
        while(right < nums.size()){
            if(nums[right] % 2) odd++;
            while(odd > k){
                if(nums[left] % 2) odd--;
                left++;
            }
            cnt += right-left+1;
            right++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countNum(nums, k) - countNum(nums, k - 1);
    }
};