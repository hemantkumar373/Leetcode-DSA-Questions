class Solution {
public:
    int firstOccur(vector<int>& nums,int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+(end-start/2));
            if(nums[mid]==target){
                ans = mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
               start=mid+1; 
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    int lastOccur(vector<int>& nums,int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+(end-start/2));
            if(nums[mid]==target){
                ans = mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
               start=mid+1; 
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccur(nums,target);
        if(first == -1) return{-1,-1};
        int last = lastOccur(nums,target);
        return {first,last};
    }
};