#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 建立K个数的小堆
        // 时间复杂度:0(N*logK)
        // 空间复杂度:0(K)
        priority_queue<int,vector<int>,greater<int>> minHeap;
        size_t i=0;
        for(;i< k; ++i)
            minHeap.push(nums[i]);
        for(;i< nums.size();++i)
        {
            if(nums[i]>minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }  
        }
        return minHeap.top();
    }
};