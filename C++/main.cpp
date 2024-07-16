#include <iostream>
#include "string"
using namespace std;

//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回-1。
//s = "leetcode"  返回0.
//s = "loveleetcode"  返回2.
//s = "aabb"  返回-1.


class Solution {
public:
    int firstUniqChar(string s) {
        //使用映射的方式统计次数
        int count[26] = {0};
        for(auto ch : s)  //for(auto i : v)遍历容器元素
        {
            count[ch - 'a']++;
        }

        for(size_t i = 0;i < s.size(); ++i)
        {
            if(count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};



//代码1：
//#include<iostream>
//#include<string>
//using namespace std;
//string s = "hello";
//for (auto &i : s ) //i是个引用 i到底引用的是什么？
//i = toupper(i); //改变成大写，影响s的值
//cout<<s<<endl; //s的值是 HELLO