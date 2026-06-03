#include <bits/stdc++.h>

//187. Repeated DNA Sequences
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        vector<string> ans;

        for (int i = 0; i + 9 < s.length(); i++) {
            string cur = s.substr(i, 10);

            if (++freq[cur] == 2) {
                ans.push_back(cur);
            }
        }

        return ans;
    }
};