class Solution {
public:
    vector<vector<string>> partition(string s) {       
        vector<vector<string>> res;
        vector<string> temp;
        solve(0, s, temp, res);
        
        return res;
    }
    
    void solve(int index, string s, vector<string> &temp, vector<vector<string>> &res) {
        if (index == s.size()) {
            res.push_back(temp);
            return;
        }
        
        for (int i = index; i < s.size(); i++) {
            if (palindromeCheck(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, temp, res);
                temp.pop_back();
            }
        }
        
        return;
    }
    
    bool palindromeCheck(string s, int start, int end) {
        while (start <= end) {
            if(s.at(start++) != s.at(end--)) {
                return false;
            }
        }
        return true;
    }
};