#include <iostream>
using namespace std;


//C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，
//也具有其返回值类型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
//函数名字为：关键字operator后面接需要重载的运算符符号。
//函数原型：返回值类型operator操作符(参数列表)
// 全局的operator==
class Date
{
public:
    int GetMonthDay(int year,int month)
    {
        static int monthDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        //是2月且是闰年返回29
        if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
            return 29;

        return monthDays[month];
    }

    Date(int year = 0, int month = 1, int day = 1)
     {
        if(year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year,month)) {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout << "ERR" << endl;
        }
         }

    bool operator==(const Date& d2)
    {
        return _year == d2._year
               && _month == d2._month
               && _day == d2._day;
    }

    bool operator<(const Date& d2)
    {
        if(_year > d2._year)
            return true;
        else if(_year == d2._year && _month < d2._month)
            return true;
        else if(_year == d2._year && _month == d2._month && _day < d2._day)
            return true;

        return false;
    }

    //复用上面的来实现
    bool operator <= (const Date& d)
    {
        return *this < d || *this == d;
    }

    bool operator > (const Date& d)
    {
        return !(*this <= d);
    }

    bool operator >= (const Date& d)
    {
        return !(*this < d);
    }

    bool operator != (const Date& d)
    {
        return !(*this == d);
    }

    //d1 + 10
    //d1 + 100
    //d1 + 1000
    Date operator+(int day)
    {
        Date ret = *this;//用d1拷贝构造一个ret
        //Date ret(*this);
        if(day < 0)
        {
            return ret - (-day);
        }
        ret._day += day;
        while(ret._day > GetMonthDay(ret._year,ret._month))
        {
            //如果日期的天数不合法，就需要往月进度
            ret._day -= GetMonthDay(ret._year,ret._month);
            ret._month++;

            if(ret._month == 13)
            {
                ret._year++;
                ret._month = 1;
            }
        }
        return ret;
    }

    Date operator+=(int day)
    {
        _day += day;
        while(_day > GetMonthDay(_year,_month))
        {
            _day -= GetMonthDay(_year,_month);
            ++_month;

            if(_month == 13)
            {
                _year++;
                _month = 1;
            }
        }
        return  *this;
    }

    //d1 + 10
    //d1 + 100
    //d1 + 1000
    Date operator-(int day)
    {
        Date ret = *this;//用d1拷贝构造一个ret
        //Date ret(*this);
        if(day < 0)
        {
            return ret + (-day);
        }
        ret._day -= day;
        while(ret._day <= 0)
        {
            ret._month--;

            if(ret._month == 0)
            {
                ret._year--;
                ret._month = 12;
            }
            //如果日期的天数不合法，就需要往月进度
            ret._day += GetMonthDay(ret._year,ret._month);
        }

        return ret;
    }

    //++d1
    Date& operator++()
    {
        *this += 1;

        return *this;//this存放的是d1的地址
    }

    //d1++
    Date operator++(int)//为了构成函数重载
    {
        Date tmp(*this);
        *this += 1;

        return tmp;//返回加之前的值
    }

    //计算两个日期之间的天数
    int operator-(const Date& d)
    {
        int flag = 1;
        Date max = *this; //拷贝构造
        Date min = d;
        if(*this < d)
        {
            max = d;
            min = *this;
            flag = -1;
        }

        int n = 0;
        while (min != max)
        {
            ++min;
            ++n;
        }
        return n*flag;
    }

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

void Test ()
{
    Date d1(2018, 10, 26);
    Date d2(2018, 12, 31);
    //cout<<(d1 > d2)<<endl;

    Date d4 = d1 - (-1000);
    d4.Print();
    d2++;
    d2.Print();
}

int main()
{
    Test();
}
