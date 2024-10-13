class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col){
        int max = -1;
        int index = -1;
        for(int i=0; i<n; i++){
            if(mat[i][col] > max){
                max = mat[i][col];
                index = i; 
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int maxIndex = findMaxIndex(mat,n,m,mid);
            int left = mid - 1 >= 0 ? mat[maxIndex][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxIndex][mid + 1] : -1;
            if(mat[maxIndex][mid] > left && mat[maxIndex][mid] > right){
                return {maxIndex, mid};
            }
            else if(mat[maxIndex][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};