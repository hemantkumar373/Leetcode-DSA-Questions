class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l = 0, r = 0;
        int minRec = k;
        int W = 0;

        while (r < n) {
            if (blocks[r] == 'W')
                W++;

            if (r - l + 1 == k) {
                minRec = min(minRec, W);
                if (blocks[l] == 'W') {
                    W--;
                }
                l++;
            }
            r++;
        }
        return minRec;
    }
};