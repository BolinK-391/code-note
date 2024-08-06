#include <iostream>
#include <cassert>
#include <string>
using namespace std;
struct Date
{
    int year = 2000;
    int month = 01;
    int day = 01;
};



namespace my_list
{
    template<class T>
    struct __list_node
    {
        __list_node<T>* _next;
        __list_node<T>* _prev;
        T _data;

        __list_node(const T& x = T())//全缺省
            :_data(x)
            ,_next(nullptr)
            ,_prev(nullptr)
        {};
    };

    //迭代器
    template<class T, class Ref, class Ptr>
    struct __list_iterator
    {
        typedef __list_node<T> Node;
        typedef __list_iterator<T,Ref,Ptr> Self;
        Node* _node;

        __list_iterator(Node* node)
            :_node(node)
        {}

        // *it
        Ref operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
            return &_node->_data; // 是取地址 不是引用
        }

        // ++it
        Self& operator++()
        {
            _node = _node->_next;
            return *this;
        }

        // it++
        Self operator++(int)
        {
            Self tmp(*this);
            //_node = _node->_next;
            ++(*this);
            return tmp;
        }

        // --it
        Self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }

        // it--
        Self operator--(int)
        {
            Self tmp(*this);
            //_node = _node->_prev;
            --(*this);
            return tmp;
        }

        // it != end()
        bool operator!=(const Self& it)
        {
            return _node != it._node;
        }

        // it == end()
        bool operator==(const Self& it)
        {
            return _node == it._node;
        }
    };

    template<class T>
    class list
    {
        typedef __list_node<T> Node;
    public:
        typedef  __list_iterator<T, T&, T*> iterator;
        typedef  __list_iterator<T, const T&, const T*> const_iterator;

        iterator begin()
        {
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }

        // 带头双向循环链表
        list()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
        }

        // lt2(lt1)
        list(const list<T>& lt)
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;

            /*const_iterator it = lt.begin();
            while(it != lt.end())
            {
                //this->pop_back(*it);
                push_back(*it);
                ++it;
            }*/

            for(auto e : lt)
                push_back(e);
        }

//        拷贝构造和赋值运算符的区别
//                是否有新对象产生，有新对象产生则是拷贝构造，否则是赋值运算符。
//
//        Test t1(10);
//
//        Test t2(20);
//
//        t1 = t2;
//
//        赋值运算符，t1 已经存在了，已经构造过了，只不过重新赋值。
//        没有产生新对象，所以调用的是赋值运算符。
//
//        Test t1(10);
//
//        Test t2 = t1;
//
//        拷贝构造，t2 之前还没有存在，在执行 Test t2 = t1 的时候才构造出来一个新的。
//        产生了新的对象，所以调用了拷贝构造。


        // lt1 = lt3
/*        list<T>& operator=(const list<T>& lt)
        {
            if(this != &lt)
            {
                clear();
                for(auto e : lt)
                    push_back(e);
            }
            return *this;
        }
*/

        list<T>& operator=(list<T> lt)
        {
            swap(_head,lt._head);
            return *this;
        }

        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        void clear()//删内容 不删头节点
        {
            iterator it = begin();
            while(it != end())
            {
                erase(it++);
            }

            cout << "ALL CLEAR" << endl;
        }

        void push_back(const T& x)
        {
            /*Node* tail = _head->_prev;
            Node* newnode = new Node(x);

            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next = _head;
            _head->_prev = newnode;*/
            insert(end(),x);
        }

        void pop_back()
        {
            //erase(iterator(_head->_prev));
            erase(--end());
        }

        void push_front(const T& x)
        {
            insert(begin(),x);
        }

        void pop_front()
        {
            erase(begin());
        }

        void insert(iterator pos, const T& x)
        {
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* newnode = new Node(x);
            // prev newnode cur
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
        }

        void erase(iterator pos)
        {
            assert(pos != end());
            Node* remove = pos._node;
            Node* prev = remove->_prev;
            Node* next = remove->_next;

            prev->_next = next;
            next->_prev = prev;
            delete remove;
        }

        void print_list()
        {
            list<T>::iterator it = begin();
            while(it != end())
            {
                cout << *it << " ";
                ++it;
            }
            cout << endl;
        }

        iterator find(const T& x)
        {
            iterator it = begin();
            while(it != end())
            {
                if(it._node->_data == x)

                    return it;
                else
                    it++;
            }
            cout << "NOT FOUND" << endl;
            return nullptr;
        }

        iterator find_Date(int year,int month,int day)
        {
            iterator it = begin();
            while(it != end())
            {
                if(it._node->_data.year == year && it._node->_data.month == month && it._node->_data.day == day)
                    return it;
                else
                    ++it;
            }
            cout << "NOT FOUND" << endl;
            return nullptr;
        }


    private:
        Node* _head;
    };


    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        lt.print_list();

        list<int>::iterator pos = lt.find(5);
        lt.erase(pos);

        list<int>::iterator it_1 = lt.begin();
        while(it_1 != lt.end())
        {
            cout << *it_1 << " ";
            ++it_1;
        }
        cout << endl;

    }

    void test_list2()
    {
        my_list::list<Date> lt;
        Date _st = {2012,12,9};
        Date _nd = {2024,8,3};
        Date _rd = {2000,5,5};
        lt.push_back(_st);
        lt.push_back(_nd);
        lt.push_back(_rd);

        my_list::list<Date>::iterator pos = lt.find_Date(2012,12,9);
        lt.erase(pos);


//      Node* cur 和 iterator it 的区别
//
//      当他们都指向同一个节点，那么在物理内存中他们都存的是这个
//      节点地址，物理上是一样的
//      但是他们的类型不一样，他们的意义就不一样，
//      比如*cur是一个指针的解引用，取到的值是节点
//      比如*it是去调用迭代器的operator*，返回值是节点中存的值。
//
//      类型决定了对空间的解释权

        my_list::list<Date>::iterator it = lt.begin();
        while(it != lt.end())
        {
            //cout << (*it).year << "-" << (*it).month << "-" << (*it).day;
            //cout << endl;
            cout << it->year << "-" << it->month << "-" << it->day;
            cout << endl;
            ++it;
        }//这里原本应该是it->->year，但是为了可读性，编译器特殊处理了一下
    }

    void test_list3()
    {
        list<int> lt1;
        lt1.push_back(1);
        lt1.push_back(2);
        lt1.push_back(3);
        lt1.push_back(4);

        list<int> lt2(lt1);
        lt2.print_list();

    }
}




int main()
{
    //my_list::test_list1();
    my_list::test_list2();
    //my_list::test_list3();
    return 0;
}