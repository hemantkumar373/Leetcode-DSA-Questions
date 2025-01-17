class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for (auto el : derived) {
            xorr ^= el;
        }
        return (xorr == 0);
    }
};