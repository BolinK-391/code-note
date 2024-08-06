#include <iostream>
#include <list>
using namespace std;

namespace my_queque  //先进先出
{
    template<class T,class Container> // <类型,容器>
    class queque
    {
    public:
        void push(const T& x)
        {
            _con.push_back(x);
        }

        void pop()
        {
            _con.pop_front();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

        T& front()
        {
            return _con.front();
        }

        T& back()
        {
            return _con.back();
        }
    private:
        Container _con;
    };

    void test_queque()
    {
        queque<int,list<int>> q;  //不能用vector，因为没有提供pop_front接口  因为头删要挪数据效率低
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);

        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
}


//stack和queue都没有迭代器，因为不允许随便便利

int main()
{
    my_queque::test_queque();
    return 0;
}