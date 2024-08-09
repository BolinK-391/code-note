#include <iostream>

using namespace std;

class Base {
public :
    virtual void func1() {cout<<"Base::func1" <<endl;}
    virtual void func2() {cout<<"Base::func2" <<endl;}
private :
    int a;
};
class Derive :public Base {  // 子类是覆盖父类的虚表所以子类没有 _vfptr指针(4字节)，直接调用父类的
public :
    virtual void func1() {cout<<"Derive::func1" <<endl;}
    virtual void func3() {cout<<"Derive::func3" <<endl;}
    virtual void func4() {cout<<"Derive::func4" <<endl;}
private :
    int b;
};
// 子类自己没有虚表
// 虚表是包含在父类继承下来的父类对象的

//void(*p)(); // 定义一个函数指针变量
typedef void(*VF_PTR)(); // 函数指针类型重定义

//打印对象虚表 -> 虚表本质是一个虚函数指针数组
void PrintVFTable(VF_PTR* pTable)
{
    for(size_t i = 0; pTable[i] != nullptr; ++i)
    {
        printf("vfTable[%d]:%p->",i,pTable[i]);
        VF_PTR f = pTable[i];
        f();
    }
    cout << endl;
}

int main()
{
    //void(*p)(); //定义一个函数指针
    //VF_PTR p;

    Base b;
    Derive d;

    //取对象中前四个字节存的虚表指针
    PrintVFTable((VF_PTR*)(*(int*)&b));
    PrintVFTable((VF_PTR*)(*(int*)&d));
    return 0;
}