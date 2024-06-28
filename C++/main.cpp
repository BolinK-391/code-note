#include <iostream>
#include "string"
using namespace std;

//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//
//字母和数字都属于字母数字字符。
//
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

class Solution
{
public:
    bool isCharOrNumber(char ch)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return true;
        else
            return false;
    }

    bool isPalindrome(string s)
    {
        //将字符串中所有的大写字母转成小写
        for(auto& ch : s)
        {
            if(ch >= 'A' && ch <= 'Z')
                ch += 32;
        }

        int begin = 0, end = s.size()-1;
        while(begin < end)
        {
            while(begin < end && !isCharOrNumber(s[begin]))
                ++begin;
            while(begin < end && !isCharOrNumber(s[end]))
                --end;

            if(s[begin] != s[end])
                return false;
            else
            {
                ++begin;
                --end;
            }
        }
        return true;
    }
};