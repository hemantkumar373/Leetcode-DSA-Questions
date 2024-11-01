class Solution {
private:
    int subarrayWithKDiff(vector<int>& nums, int k){
        int n = nums.size();
        int cnt = 0;
        int l = 0, r = 0;
        unordered_map<int,int> mpp;
        
        while(r < n){
            mpp[nums[r]]++;
            
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithKDiff(nums, k) - subarrayWithKDiff(nums, k - 1);
    }
};