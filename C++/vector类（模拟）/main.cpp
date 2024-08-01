#include <iostream>
#include <cassert>
#include <string>
using namespace std;

namespace my_vector
{
    template<class T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        vector()
            :_start(nullptr)
            ,_finish(nullptr)
            ,_end_of_storage(nullptr)
        {}

        //深拷贝
/*        vector(const vector<T>& v)
        {
            _start = new T[v.capacity()];
            _finish = _start;
            _end_of_storage = _start + v.capacity();

            for(size_t i = 0; i < v.size(); ++i)
            {
                *_finish = v[i];
                ++_finish;
            }
        }*/
        //v2(v1)
        vector(const vector<T>& v)
            :_start(nullptr)
            ,_finish(nullptr)
            ,_end_of_storage(nullptr)
        {
            reserve(v.capacity());
            for(const auto& e : v)
            {
                push_back(e);
            }
        }

//        为什么要使用深拷贝？
//
//        希望在改变新的数组（对象）的时候，不改变原数组（对象）
//        浅拷贝只复制指向某个对象的指针，而不复制对象本身，新旧对象还是共享同一块内存（分支）。
//        1.  浅拷贝是按位拷贝对象，它会创建一个新对象，这个对象有着原始对象属性值的一份精确拷贝。
//        2.  如果属性是基本类型，拷贝的就是基本类型的值；如果属性是内存地址（引用类型），拷贝的就是内存地址 ，
//            因此如果其中一个对象改变了这个地址，就会影响到另一个对象。

        //v1 = v3
        vector<T>& operator=(const vector<T>& v)
        {
            if(this != &v)
            {
                delete[] _start;
                _start = new T[v.capacity()];

                //1. new( ) 分配这种类型的一个大小的内存空间,并以括号中的值来初始化这个变量;
                //2. new[ ] 分配这种类型的n个大小的内存空间,并用默认构造函数来初始化这些变量;

                memcpy(_start,v._start, sizeof(T)*v.size());
            }
            return *this;
        }
        //C++中用new动态创建二维数组的格式一般是这样： TYPE (*p)[N] = new TYPE [][N];
        //其中，TYPE是某种类型，N是二维数组的列数。采用这种格式，列数必须指出，而行数无需指定。
        //在这里，p的类型是TYPE*[N]，即是指向一个有N列元素数组的指针。

        //v1 = v3（简洁版）
        vector<T>& operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }
        void swap(vector<T>& v)
        {
            ::swap(_start,v._start);
            ::swap(_finish,v._finish);
            ::swap(_end_of_storage,v._end_of_storage);
        }
        //值传递（Value Passing）：
        //
        //当参数以值传递的方式传递给函数时，函数内部使用的是参数值的一个副本。
        //在函数内部对参数的任何修改都不会影响原始变量。
        //值传递涉及到数据的复制，如果传递的是大型对象，可能会影响性能。

        //引用传递（Reference Passing）：
        //
        //引用传递允许函数直接访问和修改传递给它的变量。
        //函数内部使用的是参数的引用，而不是副本，因此对参数的任何修改都会反映到原始变量上。
        //引用传递不涉及数据的复制，因此对于大型对象来说，性能更好。
        //引用必须在声明时初始化，并且之后不能改变指向。

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t sz = size();
                T* tmp = new T[n];
                if(_start)
                {
                    //memcpy(tmp,_start,sizeof(T)*sz);  按字节拷贝，浅拷贝
                    for(size_t i = 0; i < sz; ++i)//调用的是T的operator=，深拷贝（赋值）
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = tmp + sz;
                _end_of_storage = tmp + n;
            }
        }

        void resize(size_t n,const T& val = T())
        {
//            更改大小
//            调整容器的大小，使其包含 n 个元素。
//
//            如果 n 小于当前容器大小，则内容将减少到其前 n 个元素，并删除超出其范围的元素（并销毁它们）。
//
//            如果 n 大于当前容器大小，则通过在末尾插入尽可能多的元素来扩展内容，以达到 n 的大小。如果指定了 val，则新元素将初始化为 val 的副本，否则，它们将进行值初始化。
//
//            如果 n 也大于当前容器容量，则会自动重新分配分配的存储空间。
//
//            请注意，此函数通过插入或擦除容器中的元素来更改容器的实际内容。
            if(n < size())
            {
                _finish = _start + n;
            }
            else
            {
                if(n > capacity())
                {
                    reserve(n);
                }
                while(_finish < _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }

        }

        void push_back(const T& x)
        {
            /*if (_finish == _end_of_storage)
            {
                size_t newcapacity = capacity() == 0 ? 2 : capacity()*2;
                reserve(newcapacity);
            }

            *_finish = x;
            ++_finish;*/
            insert(_finish,x);
        }

        void pop_back()
        {
            /*assert(_start < _finish);
            --_finish;*/

            erase(_finish - 1);
        }

        void insert(iterator pos, const T& x)
        {
            assert(pos <= _finish);

            if(_finish == _end_of_storage)
            {
                //扩容
                size_t n = pos - _start;
                size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
                reserve(newcapacity);

                //如果增容原来的pos就失效了，这里需要重新计算位置（迭代器失效）
                pos = _start + n;
            }

            iterator end = _finish - 1;
            while(end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }

            *pos = x;
            ++_finish;
        }

        iterator erase(iterator pos)
        {
            assert(pos < _finish);

            iterator it = pos;
            while(it < _finish)
            {
                *it = *(it + 1);
                ++it;
            }
            --_finish;

            return pos;
        }

        const T& operator[](size_t i) const
        {
            assert(i < size());
            return _start[i];
        }

        T& operator[](size_t i)
        {
            assert(i < size());
            return _start[i];
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        void print_vector() //只读的迭代器
        {
            const_iterator it = begin();
            while(it != end())
            {
                cout << *it << " ";
                ++it;
            }
            cout << endl;
        }

    private:
        //三个指针
        iterator _start;
        iterator _finish;
        iterator _end_of_storage;
    };


    void test_vector1()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        vector<int>::iterator it = v.begin();
        while(it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        //三种遍历方式

        v.resize(2);

        for(auto& e : v)
        {
            cout << e << " ";
        }
        cout << endl;

        for(size_t i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;

    }

    void test_vector2()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.insert(v.begin(), 0);
        v.print_vector();

        vector<int> v1 = v;
        vector<int> v2(v);

        vector<int>::iterator it = v.begin();
        while(it != v.end())
        {
            if(*it % 2 == 0)
                it = v.erase(it);
            else
                ++it;
        }
        v.print_vector();
        v1.print_vector();
        v2.print_vector();
    }
    void test_vector3()
    {
        vector<string> v;
        v.push_back("123");
        v.push_back("456");

        v.print_vector();
    }
}

int main()
{
    //my_vector::test_vector1();
    //my_vector::test_vector2();
    my_vector::test_vector3();
    return 0;
}