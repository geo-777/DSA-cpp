//q.189

#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k %= n;

        for(int i=0; i<k; i++){
            int last = nums[n-1];

            for(int j=n-1; j>0; j--) {
                nums[i] = nums[i-1];
            }
            nums[0]=last;

        }
        
    }
};