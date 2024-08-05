#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 时间复杂度:O(N*1ogN)
        // 空间复杂度:0(1)
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};