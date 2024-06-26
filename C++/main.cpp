#include <iostream>
using namespace std;

//友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声明，声明时需要加friend关键字。
class Date
{
    friend ostream& operator<<(ostream& _cout, const Date& d);
    friend istream& operator>>(istream& _cin, Date& d);
public:
    Date(int year = 1900, int month = 1, int day = 1)
            : _year(year)
            , _month(month)
            , _day(day)
    {}
private:
    int _year;
    int _month;
    int _day;
};
ostream& operator<<(ostream& _cout, const Date& d) //返回值可以连续输出
{
    _cout << d._year << "-" << d._month << "-" << d._day;
    return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
    _cin >> d._year;
    _cin >> d._month;
    _cin >> d._day;
    return _cin;
}

int main()
{
    static int monthDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month,day;
    // 这样可以不断接收输入，直到按ctrl + c就结束
    while(cin >> year >> month >> day)
    {
        int n = 0;
        //累加1-month-1月的天数
        for(int i = 1; i < month; ++i)
        {
            n += monthDays[i];
        }
        //累加month那个月的天数
        n += day;

        //闰年 +1天
        if(month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            n += 1;
        }

        cout << n << endl;
    }

    return 0;

}