class Solution {
public:
    vector<vector<string>> partition(string s) {        
        queue<vector<string>> q;
        
         // fill the queue with the initial values
        char startChar = s.at(0);
        for (int i = s.length() - 1; i >= 0; i--) {
            if (startChar == s.at(i)) {
                // check if it's a palindrome
                string subStr = s.substr(0, i + 1);
                if (palindromeCheck(subStr)) {
                    // valid palindrome, take out and add to queue
                    string remainingStr = s.substr(i + 1);
                    if (remainingStr.size() != 0) {
                        vector<string> toAdd{subStr, remainingStr};
                        q.push(toAdd);
                    } else {
                        vector<string> toAdd{subStr};
                        q.push(toAdd);
                    }
                }
            }
        }
        
        vector<vector<string>> res;
        // loop through queue
        while (!q.empty()) {
            vector<string> curr = q.front();
            q.pop();
            
            // if the last element is a palindrome, add to res and start with one less
            bool oneLess = false;
            if (palindromeCheck(curr.at(curr.size() - 1))) {
                // check if curr is in res
                bool inside = false;
                for (int i = 0; i < res.size(); i++) {
                    vector<string> toCheck = res.at(i);
                    if (curr == toCheck) {
                        inside = true;
                    }
                }
                
                if (!inside) {
                    res.push_back(curr);
                    oneLess = true;
                }
            }
            
            // else, we repeat the process above with the last substr
            string s1 = curr.at(curr.size() - 1);
            char startChar1 = s1.at(0);
            int i = s1.length() - 1;
            if (oneLess) {
                i--;
            }
            for (i; i >= 0; i--) {
                if (startChar1 == s1.at(i)) {
                    // check if it's a palindrome
                    string subStr = s1.substr(0, i + 1);
                    if (palindromeCheck(subStr)) {
                        // valid palindrome, take out and add to queue
                        string remainingStr = s1.substr(i + 1);
                        if (remainingStr.size() == 0) break;
                        vector<string> temp = curr;
                        temp.at(temp.size() - 1) = subStr;
                        temp.push_back(remainingStr);
                        q.push(temp);
                    }
                }
            }
        }
        
        return res;
    }
    
    bool palindromeCheck(string s) {
        bool valid = true;
        int lastCheck = s.size() / 2;
        for (int i = s.size() - 1; i >= lastCheck; i--) {
            if (s.at(i) != s.at(s.size() - i - 1)) {
                valid = false;
                break;
            }
        }
        return valid;
    }
};