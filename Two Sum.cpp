class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vals;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums.at(i);
            int remainder = target - curr;
            if (vals.count(remainder)) {
                return {vals[remainder], i};
            }
            vals[curr] = i;
        }

        return {};
    }
};