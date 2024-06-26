#include <iostream>
using namespace std;


//求1 + 2 + 3 + 4 + ... + n,要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句(A?B:C)

class Sum
{
public:
    Sum()
    {
        _sum += _i;
        ++_i;
    }

    //静态成员函数主要为了调用方便，不需要生成对象就能调用。
    //此时GetSum()可以直接调用，Sum::GetSum();
    //Sum()必须先生成类对象才能调用，Sum a; a.Sum();
    static int GetSum()
    {
        return _sum;
    }
    static int Init()
    {
        _i = 1;
        _sum = 0;
    }

    //静态函数不需要实例化就可以被调用，不会也不可以调用或操纵非静态成员。

private:
    static int _i;
    static int _sum;
};

//在外面进行初始化
int Sum::_i = 1;
int Sum::_sum = 0;

class Solution{
public:
    int Sum_Solution(int n)
    {
        Sum::Init();
        Sum a[n];//创建了一个对象数组，对象数组调用了n次的默认构造函数
        return Sum::GetSum();
    }
};

int main()
{
    Solution st;
    cout << st.Sum_Solution(5) << endl;
}