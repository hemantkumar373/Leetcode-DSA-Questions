class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        if(n % groupSize != 0) return false;
        
        map<int, int> mpp;
        for(auto &handNum : hand){
            mpp[handNum]++;
        }
        
        while(!mpp.empty()){
            int curr = mpp.begin()->first;
            
            for(int i = 0; i < groupSize; i++){
                if(mpp[curr + i] == 0) return false;
                
                mpp[curr + i]--;
                if(mpp[curr + i] == 0) mpp.erase(curr + i);
            }
        }
        return true;
    }
};