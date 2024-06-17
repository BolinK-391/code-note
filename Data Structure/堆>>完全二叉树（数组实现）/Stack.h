#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>


//堆
// 逻辑结构：完全二叉树
// 物理结构：数组
//作用：堆排序、TOPK


//大堆 >> 树中所有父亲大于等于孩子
//小堆 >> 树中所有父亲小于等于孩子
typedef int HPDataType;

typedef struct Heap//数组建堆
{
    HPDataType *_a;
    int _size;
    int _capacity;
}Heap;

//主要依赖向下调整算法
//调整的树的左右子树都是小堆
void Swap(HPDataType* p1,HPDataType* p2);

void AdjustDown(HPDataType * a,int n,int root);
void AdjustUp(HPDataType * a,int n,int root);

void HeapInit(Heap* php,HPDataType* a,int n);

void HeapDestroy(Heap* php);
void HeapPush(Heap* php,HPDataType x);
void HeapPop (Heap* php);

HPDataType HeapTop(Heap* php);

//输入整数数组arr,找出其中最小的k个数
int* getLeastNumbers(int* arr,int arrSize,int k);