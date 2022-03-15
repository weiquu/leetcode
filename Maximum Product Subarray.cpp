class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums.at(0);
        int prevIsIncludedMin = maxSoFar;
        int prevIsNotIncludedMin = 11;
        int prevIsIncludedMax = maxSoFar;
        int prevIsNotIncludedMax = -11;
        
        for (int i = 1; i < nums.size(); i++) {
            int nextIncludedMin = min(prevIsIncludedMin * nums.at(i), prevIsIncludedMax * nums.at(i));
            nextIncludedMin = min(nextIncludedMin, nums.at(i));
            int nextNotIncludedMin = min(prevIsIncludedMin, prevIsNotIncludedMin);
            int nextIncludedMax = max(prevIsIncludedMin * nums.at(i), prevIsIncludedMax * nums.at(i));
            nextIncludedMax = max(nextIncludedMax, nums.at(i));
            int nextNotIncludedMax = max(prevIsIncludedMax, prevIsNotIncludedMax);
            
            if (nextIncludedMax > maxSoFar) {
                maxSoFar = nextIncludedMax;
            }
            if (nextNotIncludedMax > maxSoFar) {
                maxSoFar = nextNotIncludedMax;
            }
            
            prevIsIncludedMin = nextIncludedMin;
            prevIsNotIncludedMin = nextNotIncludedMin;
            prevIsIncludedMax = nextIncludedMax;
            prevIsNotIncludedMax = nextNotIncludedMax;
        }
        
        return maxSoFar;
    }
};