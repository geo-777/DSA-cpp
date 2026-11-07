class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ind;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if(ind.find(target - nums[i]) != ind.end()){
                return {i,ind[target - nums[i]]};
            }

            ind[nums[i]]=i;
        }
        return {-1,-1};
    }
};