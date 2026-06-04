#include <bits/stdc++.h>

// q 713. Subarray product less than k
using std::vector;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int p=1;
        int count=0;
        int n=nums.size();
        int right;
        if (k <= 1) return 0;
        for (right = 0; right < n; right++) {
            p *= nums[right];

            while (p >= k) {
                p /= nums[left++];
            }

            count += right - left + 1;
        }

        return count;
        
    }
};