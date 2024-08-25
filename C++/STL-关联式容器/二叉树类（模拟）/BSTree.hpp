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
        /* 1.��Ϊ�գ�����ָ���ҵ��ң�ɾ���Լ���
           2.��Ϊ�գ�����ָ���ҵ���ɾ���Լ���
           3.���Ҷ���Ϊ�գ�����ֱ��ɾ����ʹ���滻��ɾ��
             �����������������ڵ㣨���ҽڵ㣩��������������С�ڵ㣨����ڵ㣩ȥ����� */

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
                //�ҵ��ˣ���ʼɾ��
                if(cur->_left == nullptr) // ��Ϊ��
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

                else if(cur->_right == nullptr) // ��Ϊ��
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

                else // ���Ҷ���Ϊ�գ��������
                {
                    Node* rightMinParent = cur;
                    Node* rightMin = cur->_right;
                    while(rightMin->_left)
                    {
                        rightMinParent = rightMin;
                        rightMin = rightMin->_left;
                    }

                    // ���ɾ��
                    cur->_key = rightMin->_key;

                    // ת����ɾ��rightMin
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
    diction.Insert("����","Twilight Sparkle");
    diction.Insert("ƻ���ζ�","Applejack");
    diction.Insert("�Ʊ�����","Rainbow Dash");
    diction.Insert("����","Rarity");
    diction.Insert("����","Pinkie Pie");
    diction.Insert("����","Fluttershy");

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

// ͳ�ƴ���
void TestBSTree_2()
{
    string strArr[] = {"��ȸ","��Ƥ","ĵ��","ĵ��","��ȸ"
                       ,"ĵ��","ĵ��","����","ĵ��","����"
                       ,"ϲȵ","��Ƥ","ĵ��","��Ƥ","��Ƥ"};
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