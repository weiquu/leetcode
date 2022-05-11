// curr + 2*numRows - 2, curr = 0
// curr + (numRows - i) + (numRows - i), before + 2i - 2, curr = 1

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        bool arr[s.length()];
        for (int i = 0; i < s.length(); i++) {
            arr[i] = false;
        }

        string res = "";
        for (int i = 1; i <= numRows; i++) {
            int curr = i - 1;
            if (curr < s.length() && !arr[curr]) {
                res.push_back(s.at(curr));
                arr[curr] = true;
            }
            while (curr < s.length()) {
                int nextFirst = curr + (numRows - i) + (numRows - i);
                int nextSecond = nextFirst + 2*i - 2;
                if (nextFirst < s.length() && !arr[nextFirst]) {
                    res.push_back(s.at(nextFirst));
                    arr[nextFirst] = true;
                }
                if (nextSecond < s.length() && !arr[nextSecond]) {
                    res.push_back(s.at(nextSecond));
                    arr[nextSecond] = true;
                }
                if (curr == nextSecond) {
                    break;
                }
                curr = nextSecond;
            }
        }

        return res;
    }
};