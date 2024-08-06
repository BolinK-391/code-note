#include <cstring>
#include <cassert>

//实现一个支持增删查改的string

namespace my_string
{
    class string
    {
    public:
    //迭代器
    typedef char* iterator;
    iterator begin()
    {
        return _str;
    }
    iterator end()
    {
        return _str + _size;
    }

    /*    string()
            :_str(new char[1])
        {
            _str[0] = '\0';
        }

        string(char* str)
            :_str(new char[strlen(str) + 1])//_str指向的空间在堆上面  如果只是单纯的拷贝的话就是在常数区  _str在栈上面
        {
            strcpy(_str,str);
            //strcpy会把\0拷过去
        }*/

    //全缺省版本
    /*    string(const char* str = "")
                :_str(new char[strlen(str) + 1])//_str指向的空间在堆上面  如果只是单纯的拷贝的话就是在常数区  _str在栈上面
        {
            strcpy(_str,str);
            //strcpy会把\0拷过去
        }
    */
        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1]; //'\0'不是有效字符
            strcpy(_str,str);
        }

        //string s2(s1) -> 深拷贝
        //浅拷贝只是值传递  如果将s1的值浅拷贝传递给s2  s2和s1指向的是同一个空间  如果s1改变s2也会改变
        //深拷贝是两个不同的空间，就不会发生改变一个另一个也改变的情况
        string(const string& s)
            :_str(new char[strlen(s._str) + 1])
        {
            strcpy(_str,s._str);
        }

        //实现赋值
        //s1 = s3
        //s1 = s1
        string& operator=(const string& s)
        {
            if(this != &s)
            {
                char* tmp = new char[strlen(s._str) + 1];
                strcpy(tmp,s._str);
                delete[] _str;
                _str = tmp;
            }

            return *this;
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        size_t size() const
        {
            return _size;
        }

        size_t capacity() const
        {
            return _capacity;
        }

        char& operator[](size_t i)
        {
            assert(i < _size);
            return _str[i];
        }

        const char& operator[](size_t i) const
        {
            assert(i < _size);
            return _str[i];
        }

        const char* c_str()
        {
            return _str;
        }

        void reserve(size_t n)
        {
            if(n > _capacity)
            {
                char *newstr = new char[n + 1];
                strcpy(newstr, _str);
                delete[] _str;
                _str = newstr;
                _capacity = n;
            }
        }

        void resize(size_t n,char ch = '\0')
        {
            //三种情况
            if (n < _size)
            {
                _str[n] = '\0';
                _size = n;
            }
            else
            {
                if(n > _capacity)
                    reserve(n);

                for(size_t i = _size; i < n; ++i)
                {
                    _str[i] = ch;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }

        void push_back(char ch)  //插入字符
        {
//            //空间满了则进行增容
//            if(_size == _capacity)
//            {
//                size_t newcapacity = _capacity == 0 ? 2 : _capacity*2;
//                reserve(newcapacity);
//            }
//
//            _str[_size] = ch;
//            ++_size;
//            _str[_size] = '\0';
            insert(_size,ch);

        }
        void append(const char* str)  //插入字符串
        {
//            //空间不够增容
//            size_t len = strlen(str);
//            if(_size + len > _capacity)   //注意不能按2倍去增，因为可能会不够
//                reserve(_size + len);
//
//            strcpy(_str + _size, str);
//            _size += len;
            insert(_size,str);
        }

        //s1 += 'a'
        string& operator+=(char ch)
        {
            this->push_back(ch);
            return *this;
        }

        string& operator+=(const char* str)
        {
            this->append(str);
            return *this;
        }

        string& insert(size_t pos, char ch)
        {
            assert(pos <= _size);
            if(_size == _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 2 : _capacity*2;
                reserve(newcapacity);
            }

            int end = _size;
            while(end >= (int)pos)
            {
                _str[end+1] = _str[end];
                --end;
            }
            _str[pos] = ch;
            ++_size;

            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            //空间不够增容
            size_t len = strlen(str);
            if(_size + len > _capacity)   //注意不能按2倍去增，因为可能会不够
                reserve(_size + len);

            int end = _size;
            while(end >= (int)pos)
            {
                _str[end+len] = _str[end];
                --end;
            }

            int i = 0;
            int keep_len = len;
            /*while(len)
            {
                _str[pos++] = str[i++];
                len--;
            }*/
            strncpy(_str + pos,str,len);  //strcpy会把'\0'也给拷贝过来,strncpy则不会
            _size += keep_len;

            return *this;
        }

        void erase(size_t pos, size_t len = npos)
        {
            assert(pos < _size);
            if(len >= _size - pos)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                size_t i = pos + len;
                while(i <= _size)
                {
                    _str[i-len] = _str[i];
                    ++i;
                }

                _size -= len;
            }
        }
        size_t find(char ch,size_t pos = 0)
        {
            for(size_t i = pos; i < _size; ++i)
            {
                if(_str[i] == ch)
                    return i;
            }

            return npos;
        }
        size_t find(const char* str,size_t pos = 0)
        {
            char* p = strstr(_str,str);
            if(p == nullptr)
                return npos;
            else
                return p - _str;
        }

        //s1 < s2
        bool operator<(const string& s)
        {
            int ret = strcmp(_str,s._str);
            return ret;
        }

        bool operator==(const string& s)
        {
            int ret = strcmp(_str,s._str);
            return ret == 0;
        }

        bool operator<=(const string& s)
        {
            return *this < s || *this == s;
        }

        bool operator>(const string& s)
        {
            return !(*this < s);
        }

        bool operator>=(const string& s)
        {
            return !(*this <= s);
        }

        bool operator!=(const string& s)
        {
            return !(*this == s);
        }

    private:
        char* _str;
        size_t _size;      //已经有多少个有效字符
        size_t _capacity;  //能存多少个有效字符

        static size_t npos;
    };

    size_t string::npos = -1;

    istream &operator>>(istream& in,string& s)
    {
        while(1)
        {
           char ch;
           //in >> ch;
           ch = in.get(); //只接收一个字符
            if(ch == ' ' || ch == '\n')
            {
                break;
            }
            else
                s += ch;
        }
    }

    ostream &operator<<(ostream& out,const string& s)
    {
        for(size_t i = 0; i < s.size(); ++i)
        {
            cout << s[i];
        }

        return out;
    }

    void test_string1()
    {
        string s1("hello");
        string s2;

        cout << s1 << endl;
        cout << s2 << endl;

        //三种遍历方式
        for(size_t i = 0; i < s2.size(); ++i)
        {
            s2[i] += 1;
            cout << s2[i] << " ";
        }

        //迭代器遍历
        string::iterator it2 = s2.begin();
        while (it2 != s2.end())
        {
            *it2 -= 1;
            cout << *it2 << " ";
            ++it2;
        }
        cout << endl;

        //范围for是由迭代器支持的，也就是说这段代码最终会被编译器替换成迭代器
        for(auto e : s2)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_string2()
    {
        string s1("hello");
        s1.push_back(' ');
        s1.push_back('w');
        s1.push_back('o');
        s1.append("rld XXXXX");
        cout << s1 << endl;

        string s2;
        s2 += "hello";
        s2 += " ";
        s2 += "world";

        char s3[5] = "abcd";
        s1.insert(6,s3);
        s1.erase(2,4);
        cout << s1.find("rld") << endl;

        cout << s1 << endl;
        //cout << s2 << endl;
    }
}
