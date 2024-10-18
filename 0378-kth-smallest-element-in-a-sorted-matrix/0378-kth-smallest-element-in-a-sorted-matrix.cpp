class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low < high){
            int mid = low + (high - low) / 2;
            int cnt = 0;
            int j = n - 1; 
            
            for(int i=0; i<n; i++){
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                cnt += (j + 1);
            }
            if(cnt < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};