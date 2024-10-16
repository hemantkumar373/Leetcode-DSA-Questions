class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int maxArea = 0;
        
        while(start < end){
            int area = min(height[start], height[end]) * (end - start);
            maxArea = max(maxArea, area);
            if(height[start] < height[end]) start++;
            else end--;
        }
        return maxArea;
    }
};