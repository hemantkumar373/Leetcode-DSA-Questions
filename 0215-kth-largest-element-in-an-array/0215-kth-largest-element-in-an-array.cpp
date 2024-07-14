class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for(int i=0; i<k; i++){
            heap.push(nums[i]);
        }
        
        for(int i=k; i<nums.size(); i++){
            if(nums[i] > heap.top()){
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};