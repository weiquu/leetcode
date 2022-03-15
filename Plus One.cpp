class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool done = false;
        int curr = digits.size() - 1;
        while (!done && curr != -1) {
            int digit = digits[curr];
            if (digit < 9) {
                digits[curr]++;
                done = true;
            } else {
                digits[curr] = 0;
                curr--;
            }
        }
        
        if (!done) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};