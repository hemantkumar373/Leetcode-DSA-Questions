class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        for(auto i : nums) {
            mpp[i]++;
        }
        
        for(auto &i : mpp) {
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        while(k--) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};