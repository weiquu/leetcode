class Solution {
public:
    string longestPalindrome(string s) {
        string oddLengthString = "#";
        for (char c : s) {
            oddLengthString.push_back(c);
            oddLengthString.push_back('#');
        }

        int maxLength = 0;
        int maxStart = 0;
        int maxEnd = 0;
        for (int i = 0; i < oddLengthString.length(); i++) {
            int start = i;
            int end = i;
            while (start >= 0 && end < oddLengthString.length() && oddLengthString.at(start) == oddLengthString.at(end)) {
                start--;
                end++;
            }
            int currLength = end - start - 1;
            if (currLength > maxLength) {
                maxLength = currLength;
                maxStart = start + 1;
                maxEnd = end - 1;
            }
        }

        string res = "";
        for (int i = maxStart; i <= maxEnd; i++) {
            if (oddLengthString.at(i) != '#') {
                res.push_back(oddLengthString.at(i));
            }
        }

        return res;
    }
};