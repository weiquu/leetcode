class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum3Helper(k, n, 1);
    }

public:
    vector<vector<int>> combinationSum3Helper(int k, int n, int smallestNum) {
        if (k == 1 && n >= smallestNum && n <= 9) {
            vector<int> v;
            v.push_back(n);
            vector<vector<int>> res;
            res.push_back(v);
            return res;
        } else if (k == 0 || n < smallestNum || smallestNum > 9) {
            vector<vector<int>> res;
            return res;
        }

        vector<vector<int>> res;
        vector<vector<int>> withSmallestNum = combinationSum3Helper(k - 1, n - smallestNum, smallestNum + 1);
        for (vector<int> v : withSmallestNum) {
            v.push_back(smallestNum);
            res.push_back(v);
        }
        vector<vector<int>> withoutSmallestNum = combinationSum3Helper(k, n, smallestNum + 1);
        for (vector<int> v : withoutSmallestNum) {
            res.push_back(v);
        }

        return res;
    }
};