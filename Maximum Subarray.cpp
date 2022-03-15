class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums.at(0);
        vector<int> isIncluded;
        vector<int> isNotIncluded;
        isIncluded.push_back(maxSoFar);
        isNotIncluded.push_back(-100000);
        
        for (int i = 1; i < nums.size(); i++) {
            int nextIncluded = max(isIncluded.at(i - 1) + nums.at(i), nums.at(i));
            int nextNotIncluded = max(isIncluded.at(i - 1), isNotIncluded.at(i - 1));
            if (nextIncluded > maxSoFar) {
                maxSoFar = nextIncluded;
            }
            if (nextNotIncluded > maxSoFar) {
                maxSoFar = nextNotIncluded;
            }
            
            isIncluded.push_back(nextIncluded);
            isNotIncluded.push_back(nextNotIncluded);
        }
        
        return maxSoFar;
    }
};