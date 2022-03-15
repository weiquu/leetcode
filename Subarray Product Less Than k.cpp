class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int currProd = 1;
        int backPointer = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // backPointer < i, we know currProd (product from backPointer to i - 1 inclusive) and can decrease it from backPointer
            bool done = false;
            while (!done) {
                if (backPointer > i) {
                    done = true;
                } else if (currProd * nums.at(i) < k) {
                    // we are done for this num
                    currProd *= nums.at(i);
                    res += (i - backPointer + 1);
                    done = true;
                } else {
                    // decrement currProd, increase backPointer
                    currProd = max(currProd / nums.at(backPointer), 1);
                    backPointer++;
                }
            }
        }
        
        return res;
    }
};