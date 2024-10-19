class Solution {
public:
    void findComb(int i,vector<int>& arr,int target,vector<int>&ds,vector<vector<int>>& ans)
    {
        if(i == arr.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        
        if(arr[i] <= target){
            ds.push_back(arr[i]);
            findComb(i, arr, target - arr[i], ds, ans);
            ds.pop_back();
        }
        
        findComb(i+1, arr, target, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, candidates, target, ds, ans);
        return ans;
    }
};