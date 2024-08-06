#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace my_priority_queue
{
    //默认是大堆
    template<class T,class Container = vector<T>,class Compare = less<T>>
    class priority_queue
    {
    public:
        void AdjustUp(int child) //向上调整
        {
            Compare com;
            int parent = (child - 1) / 2;
            while(child > 0)
            {
                //if(_con[child] > _con[parent])
                if(com(_con[parent],_con[child]))
                {
                    swap(_con[parent],_con[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }

        void AdjustDwon(int root)
        {
            int parent = root;
            int child = parent *2 + 1;

            Compare com;
            while(child < _con.size())
            {
                // 选出左右孩子中大的那一个
                //if(child+1 < _con.size() && _con[child+1] > _con[child])
                if(child+1 < _con.size() && com(_con[child],_con[child+1]))
                {
                    ++child;
                }

                //if(_con[child] > _con[parent])
                if(com(_con[parent],_con[child]))
                {
                    swap(_con[child],_con[parent]);
                    parent = child;
                    child = parent * 2 +1;
                }
                else
                {
                    break;
                }
            }
        }

        void push(const T& x) //插入 向上调整
        {
           _con.push_back(x);
           AdjustUp(_con.size() - 1);
        }

        void pop() //删除 向下调整
        {
            swap(_con[0],_con[_con.size() - 1]);
            _con.pop_back();

            //O(logN)
            AdjustDwon(0);
        }

        T& top()
        {
            return _con[0];
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

    private:
        Container _con;
    };

    void test_priority_queue()
    {
        //priority_queue<int> pq;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(3);
        pq.push(1);
        pq.push(9);
        pq.push(4);
        pq.push(2);

        while(!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}

namespace my_priority_queue {
// 除了默认访问限定符不一样，struct和class在C++中是一样的
// 一般情况，成员部分私有，部分共有，就用class
// 所有成员都开放成共有，就用struct
    template<class T>
    struct less // 仿函数 函数对象
    {
        bool operator()(const T &x1, const T &x2) {
            return x1 < x2;
        }
    };

    template<class T>
    struct greater // 仿函数 函数对象
    {
        bool operator()(const T &x1, const T &x2) {
            return x1 > x2;
        }
    };
}

void test_sort()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);

    // 升序 less <
    sort(v.begin(),v.end());

    for(auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    // 降序 greater >
    //greater<int> gt;
    //sort(v.begin(),v.end(),gt);
    sort(v.begin(),v.end(),greater<int>());

    for(auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

}

int main()
{
    //my_priority_queue::test_priority_queue();

    //my_priority_queue::less<int> lessFunc;
    // cout << lessFunc(1,2) << endl; // lessFunc.operator()(1,2)
    test_sort();
    return 0;
}