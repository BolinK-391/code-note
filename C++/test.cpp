#include <iostream>
using namespace std;
#include "string.h"

//简易版本
class string
{
public:
    string(const char* str = "")
        :_str(new char[strlen(str) + 1])
    {
        strcpy(_str,str);
    }

    //string s2(s1)
    //深拷贝 —— 传统写法
    string(const string& s)
        :_str(new char[strlen(s._str)+1])
    {
        strcpy(_str,s._str);
    }
    //深拷贝 —— 现代写法
    string(const string& s)
        :_str(nullptr)
    {
       string tmp(s._str);
       swap(_str,tmp._str);
    }

    //s1 = s2
    //赋值 —— 传统写法
    string& operator=(const string& s)
    {
        if(this != &s)
        {
            char* tmp = new char[strlen(s._str)+1];
            strcpy(tmp,s._str);
            delete[] _str;
            _str = tmp;
        }
    }
    //赋值 —— 现代写法
    string& operator=(const string& s)
    {
        if(this != &s)
        {
            string tmp(s);
            swap(_str,tmp._str);
        }

        return *this;
    }

    //更简洁
    string& operator=(string s)  //传值
    {
        swap(_str,s._str);
        return *this;
    }


    ~string()
    {
        delete[] _str;
        _str = nullptr;
    }

    size_t size()
    {
        return strlen(_str);
    }

    char& operator[](size_t i)
    {
        return _str[i];
    }

private:
    char* _str;
};

int main()
{
    my_string::test_string2();
    return 0;
}