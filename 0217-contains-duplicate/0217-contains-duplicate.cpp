class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> ans;
        for(auto it : nums){
            if(ans[it] >= 1) return true;
            ans[it]++;
        }
        return false;
    }
};