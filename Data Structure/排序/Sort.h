#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>




// 排序实现的接口

// 插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现

// 快速排序hoare版本
int PartSort1(int* a, int left, int right);

// 快速排序挖坑法
int PartSort2(int* a, int left, int right);

// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// 快速排序 非递归实现（栈模拟实现）
void QuickSortNonR(int* a, int left, int right);

// 归并排序递归实现
void MergeSort(int* a, int n);

// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a,int n);


void PrintArray(int* a,int n);
void Swap(int *p1,int *p2);
int GetMidIndex(int *a,int begin,int end);
void MergeArr(int* a, int begin_1, int end_1, int begin_2, int end_2, int* tmp);

const char* MergeSortFile(const char* file);
