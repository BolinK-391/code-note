#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>


typedef int STDataType;

//静态
//struct Stack
//{
//    int _a[N];
//    int _size;
//};

typedef struct Stack
{
    STDataType* _a;
    STDataType _top;     //栈顶下表
    STDataType _capacity;
}Stack;

//初始化和销毁
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

//入栈
void StackPush(Stack* pst,STDataType x);
//出栈
void StackPop(Stack* pst);

//获取数据个数
int StackSize(Stack* pst);//保持接口的一致性

//返回1是空，返回0是非空
int StackEmpty(Stack*pst);

//获取栈顶的数据
STDataType StackTop(Stack* pst);