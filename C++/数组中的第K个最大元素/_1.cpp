#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 时间复杂度:(O(N*1OgN)
        // 空间复杂度:0(N)
        priority_queue<int> pq;
        for(auto e : nums)
            pq.push(e);

        while(--k)
            pq.pop();
        return pq.top();
    }
};