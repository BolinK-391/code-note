#include <iostream>
#include "string"
using namespace std;

//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。
//如果不存在，则返回 -1 。

class Solution
{
public:
    static int firstUniqChar(string s)
    {
        //使用映射的方式统计次数
        int count[26] = {0};
        for(auto ch:s)
        {
            count[ch - 'a']++;
        }

        for(size_t i = 0; i < s.size(); ++i)
        {
            if(count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
//    输入: s = "aabb"
//    输出: -1

    string s = "aabb";
    int a = (Solution::firstUniqChar(s));
     cout << a << endl;
}

