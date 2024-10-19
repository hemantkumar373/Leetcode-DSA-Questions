class Solution {
private:
    void findComb(int index,string digits,vector<string>& ans,string output,string mapp[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        int num = digits[index] - '0';
        string val = mapp[num];
        
        for(int i=0; i<val.length(); i++){
            output.push_back(val[i]);
            findComb(index+1, digits, ans, output, mapp);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string output;
        string mapp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        findComb(0, digits, ans, output, mapp);
        return ans;
    }
};