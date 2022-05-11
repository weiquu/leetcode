class Solution {
public:
    int countVowelStrings(int n) {
        int arr[n + 1][6];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 5; j++) {
                arr[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            arr[i][1] = 1;
        }
        for (int i = 1; i <= 5; i++) {
            arr[1][i] = i;
        }
        return countVowelStringsHelper(n, 5, arr);
    }
public:
    int countVowelStringsHelper(int n, int vowels, int arr[][6]) {
        if (arr[n][vowels] != 0) return arr[n][vowels];

        int res = 0;
        for (int i = 1; i <= vowels; i++) {
            res += countVowelStringsHelper(n - 1, i, arr);
        }
        arr[n][vowels] = res;
        return arr[n][vowels];
    }
};