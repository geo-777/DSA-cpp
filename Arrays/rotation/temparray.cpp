//q.189

#include <algorithm>
#include <vector>
using std::vector;


//right rotation

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k %= n;

        vector<int> temp(n);

        //shift last k elements to beginnig

        for(int i=0; i<k; i++){
            temp[i]=nums[n-k+i];
        }

        //shifting remaining
        for(int i=0; i<n-k; i++){
            temp[i+k] = nums[i];
        }

        nums=temp;
        
    }
};

//left rotation
class SolutionLeft {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k %= n;

        vector<int> temp(n);

        for(int i=0; i<n-k; i++){
            temp[i] = nums[i+k];
        }

        for(int i=0; i<k; i++){
            temp[n-k+i]=nums[i];
        }
        nums=temp;
        
    }
};