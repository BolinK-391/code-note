#include <iostream>
#include <string>
using namespace std;


template<class K, class V>
struct BSTreeNode // Binary Search Tree
{
    BSTreeNode<K,V>* _left;
    BSTreeNode<K,V>* _right;

    K _key;
    V _value;

    BSTreeNode(const K& key,const V& value)
        :_left(nullptr)
        ,_right(nullptr)
        ,_key(key)
        ,_value(value)
    {}
};

template<class K,class V>
class BSTree // Binary Search Tree
{
    typedef BSTreeNode<K,V> Node;
public:
    bool Insert(const K& key, const V& value)
    {
        if(_root == nullptr)
        {
           _root = new Node(key,value);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }

        cur = new Node(key,value);
        if(parent->_key < key)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        return true;
    }

    Node* Find(const K& key)
    {
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key < key)
            {
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }

    bool Erase(const K& key)
    {
        /* 1.左为空，父亲指向我的右（删除自己）
           2.右为空，父亲指向我的左（删除自己）
           3.左右都不为空，不能直接删除，使用替换法删除
             可以找左子树的最大节点（最右节点）或者右子树的最小节点（最左节点）去替代它 */

        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                //找到了，开始删除
                if(cur->_left == nullptr) // 左为空
                {
                    if(cur == _root)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if(parent->_right == cur)
                            parent->_right = cur->_right;
                        else
                            parent->_left = cur->_right;

                        delete cur;
                    }
                }

                else if(cur->_right == nullptr) // 右为空
                {
                    if(cur == _root)
                    {
                        _root = cur->_left;
                    }
                    else
                    {
                        if(parent->_left == cur)
                            parent->_left = cur->_left;
                        else
                            parent->_right = cur->_left;

                        delete cur;
                    }
                }

                else // 左右都不为空（替代法）
                {
                    Node* rightMinParent = cur;
                    Node* rightMin = cur->_right;
                    while(rightMin->_left)
                    {
                        rightMinParent = rightMin;
                        rightMin = rightMin->_left;
                    }

                    // 替代删除
                    cur->_key = rightMin->_key;

                    // 转换成删除rightMin
                    if(rightMinParent->_left == rightMin)
                        rightMinParent->_left = rightMin->_right;
                    else
                        rightMinParent->_right = rightMin->_right;
                    delete rightMin;
                }
                return true;
            }
        }
        return false;
    }

    void _InOrder(Node* root)
    {
        if(root == nullptr)
            return;

        _InOrder(root->_left);
        cout << root->_key << " : " << root->_value << endl;
        _InOrder(root->_right);
    }

    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

private:
    Node* _root = nullptr;
};

void TestBSTree_1()
{
    BSTree<string,string> diction;
    diction.Insert("紫悦","Twilight Sparkle");
    diction.Insert("苹果嘉儿","Applejack");
    diction.Insert("云宝黛西","Rainbow Dash");
    diction.Insert("珍奇","Rarity");
    diction.Insert("碧琪","Pinkie Pie");
    diction.Insert("柔柔","Fluttershy");

    diction.InOrder();
    string str;
    cout << "Search for :" << endl;
    while(cin >> str)
    {
        BSTreeNode<string,string>* ret = diction.Find(str);
        if(ret)
        {
            cout << endl;
            cout << ret->_value << endl;
        }
        else
        {
            cout << endl;
            cout << "Can't find that pony" << endl;
        }
    }
}

// 统计次数
void TestBSTree_2()
{
    string strArr[] = {"麻雀","虎皮","牡丹","牡丹","麻雀"
                       ,"牡丹","牡丹","和尚","牡丹","和尚"
                       ,"喜鹊","虎皮","牡丹","虎皮","虎皮"};
    BSTree<string,int> countTree;
    for(auto str : strArr)
    {
        BSTreeNode<string,int>* ret = countTree.Find(str);
        if (ret == nullptr)
        {
            countTree.Insert(str,1);
        }
        else
        {
            ret->_value++;
        }
    }

    countTree.InOrder();
}