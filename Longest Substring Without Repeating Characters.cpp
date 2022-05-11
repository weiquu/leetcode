class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[128];
        for (int i = 0; i < 128; i++) {
            arr[i] = -1;
        }
        int maxLength = 0;
        int starting = 0;
        int currLength = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            int currChar = c;
            if (arr[currChar] >= starting) {
                maxLength = max(maxLength, currLength);
                currLength -= (arr[currChar] - starting);
                starting = arr[currChar] + 1;
                arr[currChar] = i;
            } else {
                arr[currChar] = i;
                currLength++;
            }
        }
        maxLength = max(maxLength, currLength);

        return maxLength;
    }
};