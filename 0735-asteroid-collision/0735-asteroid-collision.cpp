class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> arr;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0) arr.push_back(asteroids[i]);
            else{
            while(!arr.empty() && arr.back() > 0 && arr.back() < abs(asteroids[i])){
                arr.pop_back();
            }
                
            if(!arr.empty() && arr.back() == abs(asteroids[i])){
                arr.pop_back();
            }
                else if(arr.empty() || arr.back() < 0){
                    arr.push_back(asteroids[i]);
                }
            }
        }
        return arr;
    }
};