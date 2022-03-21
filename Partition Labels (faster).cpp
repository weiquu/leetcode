class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        // get end pos of each letter
        vector<int> ends(26, 0);
        for (int i = 0; i < s.size(); i++) {
            ends[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;
        // go through string, get end of each character
        for (int i = 0; i < s.size(); i++) {
            end = max(end, ends[s[i] - 'a']);
            
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return res;
     }
};