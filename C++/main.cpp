#include <iostream>
#include <vector>
using namespace std;


//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        //vector<int> v;   v[i] 类型是一个int
        //vector<vector<int>> vv;   vv[i] 类型vector<int> // vv[i][j] 类型是一个int
        vector<vector<int>> vv;  //有点类似于C中的二维数组  但是注意这里是两个operator[]的函数调用实现的

        vv.resize(numRows);
        for(size_t i = 0; i < numRows; ++i)
        {
            vv[i].resize(i+1);
            vv[i][0] = 1;
            vv[i][vv[i].size()-1] = 1;
        }

        for(size_t i = 0; i < vv.size(); ++i)
        {
            for(size_t j = 0; j < vv[i].size(); ++j)
            {
                // 上一行的下标相同的那个和前一个相加
                if(vv[i][j] != 1)
                {
                    vv[i][j] = vv[i-1][j] + vv[i-1][j-1];
                }
            }
        }
        return vv;
    }
};
