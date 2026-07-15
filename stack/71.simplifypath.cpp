#include <algorithm>
#include <vector>
#include<string>
#include <sstream>
using std::stringstream;
using std::vector;
using std::string;

class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        stringstream ss(path);

        vector<string> parts;
        string part;

        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") {
                continue;
            } else if (part == "..") {
                if (!parts.empty())
                    parts.pop_back();
            } else {
                parts.push_back(part);
            }
        }

        if (parts.empty())
            return "/";

        for (string &p : parts) {
            ans += "/" + p;
        }

        return ans;
    }
};