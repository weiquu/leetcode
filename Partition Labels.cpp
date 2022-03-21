class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        queue<char> q;
        // i = 0
        int i = 0;
        // while we are not at the end of the string (i < s.size())
        while (i < s.size()) {
            // add first to queue
            q.push(s.at(i));
            int end = i;
            // while queue is not empty
            while (!q.empty()) {
                // pop letter off queue, that is current letter
                char currLetter = q.front();
                q.pop();
                set<char> temp;
                // record down letters seen as we go through string
                for (int pointer = end + 1; pointer < s.size(); pointer++) {
                    // if we encounter another current letter, 
                    if (s.at(pointer) == currLetter) {
                        // TODO: add all letters seen so far to queue
                        for (auto it = temp.begin(); it != temp.end(); it++) {
                            q.push(*it);
                        }
                        temp.clear();
                        // and set end to that
                        end = pointer;
                    } else {
                        // record down letter
                        temp.insert(s.at(pointer));
                    }
                }
            // at the end of string, dont need add the current record
            }
            // size = end - i + 1
            int size = end - i + 1;
            res.push_back(size);
            // set i to end + 1
            i = end + 1;
        // end loop
        }
        
        return res;
        // worst case n^2 (for each letter, we go through the whole string --> n * n = n^2)
    }
};