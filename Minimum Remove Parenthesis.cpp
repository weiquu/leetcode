class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int brackets = 0;
        stack<int> bracketStack;
        vector<int> toRemove;
        // if encounter close and brackets = 0, then can remove
        // if brackets is > 0 at the end, remove all brackets in the positions in the stack
        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            if (c == '(') {
                brackets++;
                bracketStack.push(i);
            } else if (c == ')') {
                if (brackets > 0) {
                    brackets--;
                    bracketStack.pop();
                } else {
                    toRemove.push_back(i);
                }
            }
        }
                
        if (brackets != 0) {
            while (!bracketStack.empty()) {
                int pos = bracketStack.top();
                bracketStack.pop();
                toRemove.push_back(pos);
            }
        }
        
        if (toRemove.size() == 0) return s;
        
        sort(toRemove.begin(), toRemove.end());
        
//         for (int i = toRemove.size() - 1; i >= 0; i--) {
//             s.erase(toRemove.at(i), 1);
//         }
        
//         return s;

        string res = "";
        int pos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (pos < toRemove.size() && i == toRemove.at(pos)) {
                pos++;
            } else {
                res += s.at(i);
            }
        }
        
        return res;
    }
};