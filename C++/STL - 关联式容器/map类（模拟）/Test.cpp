#include <iostream>
#include <map>
#include <string>
using namespace std;


class Count {
public:
    // ͳ�ƴ���
    static void CountMap_1() {
        string strArr[] = {"��ȸ", "��Ƥ", "ĵ��", "ĵ��", "��ȸ", "ĵ��", "ĵ��", "����", "ĵ��", "����", "ϲȵ",
                           "��Ƥ", "ĵ��", "��Ƥ", "��Ƥ"};
        map<string, int> countMap;
        for (auto& str: strArr) {
            map<string, int>::iterator ret = countMap.find(str);
            if (ret != countMap.end())
            {
                // (*ret).second++;
                ret->second++;
            }
            else
            {
                countMap.insert(make_pair(str,1));
            }
        }
        for(auto& e : countMap)
        {
            cout << e.first << ":" << e.second << endl;
        }
    }

    static void CountMap_2() {
        string strArr[] = {"��ȸ", "��Ƥ", "ĵ��", "ĵ��", "��ȸ", "ĵ��", "ĵ��", "����", "ĵ��", "����", "ϲȵ",
                           "��Ƥ", "ĵ��", "��Ƥ", "��Ƥ"};
        map<string, int> countMap;
        for (auto& str: strArr) {
            // 1.���ˮ��û��map�У������ɹ�
            // 2.���ˮ���Ѿ���map�У�����ʧ�ܣ�ͨ������ֵ�õ�ˮ�����ڵĽڵ��������++����
            pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str,1));
            if (ret.second == false)
            {
                ret.first->second++;
            }
        }
        for(auto& e : countMap)
        {
            cout << e.first << ":" << e.second << endl;
        }
    }

    static void CountMap_3() {
        string strArr[] = {"��ȸ", "��Ƥ", "ĵ��", "ĵ��", "��ȸ", "ĵ��", "ĵ��", "����", "ĵ��", "����", "ϲȵ",
                           "��Ƥ", "ĵ��", "��Ƥ", "��Ƥ"};
        map<string, int> countMap;
        for (auto &str: strArr) {
            // 1����������Ʒ�ֲ���map�У���operator[]�����pair<str,0>����ӳ���(����)�����ý�����++��
            // 2����������Ʒ����map�У���operator[]����ˮ����Ӧ��ӳ�����(����)�����ã�����++��
            countMap[str]++;
        }
        for(auto& e : countMap)
        {
            cout << e.first << ":" << e.second << endl;
        }
    }
    /* map��operator[]��������
       1������
       2������k��Ӧ��ӳ�����
       3���޸�k��Ӧ��ӳ����� */

    /* mapped_type& operator[](const key_type& k)
    {
        return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
    } */

    // Ϊʲô���ﲻ��find��ʵ����?
    // ԭ��:������find�����map��û�����k����η���?
    //
    // ������insert
    // 1�����k����map�У������pair<k,mapped type()>���ٷ���ӳ����������
    // 2�����k��map�У������ʧ�ܣ�����k���ڽڵ��е�ӳ����������
};

int main()
{
    Count::CountMap_1();
    cout << endl;
    Count::CountMap_2();
    cout << endl;
    Count::CountMap_3();
}