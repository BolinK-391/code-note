#include "Sort.h"

void TestInsertSort()
{
    int a[] = {3,1,4,1,7,9,8,2,0,5};
    InsertSort(a,sizeof (a) / sizeof (int));
    PrintArray(a,sizeof (a) / sizeof (int));
}

void TestShellSort()
{
    int a[] = {9,1,2,7,9,3,4,5,10,8};
    ShellSort(a,sizeof (a) / sizeof (int));
    PrintArray(a,sizeof (a) / sizeof (int));
}

void TestQuickSort()
{
    int a[] = {6,1,2,7,9,3,4,8,10,5};
    QuickSort(a,0,sizeof (a) / sizeof(int) - 1);
    PrintArray(a,sizeof (a) / sizeof (int));
}

void TestQuickSortNonR()
{
    int a[] = {6,1,2,7,9,3,4,8,10,5};
    QuickSortNonR(a,0,sizeof (a) / sizeof(int) - 1);
    PrintArray(a,sizeof (a) / sizeof (int));
}

void TestMergeSort()
{
    int a[] = {6,1,2,7,9,3,4,8,10,5};
    MergeSortNonR(a,sizeof (a) / sizeof(int));
    PrintArray(a,sizeof (a) / sizeof (int));
}

void TetsCountSort()
{
    int a[] = {1,1,1,7,0,3,4,8,10,5};
    CountSort(a,sizeof (a) / sizeof(int));
    PrintArray(a,sizeof (a) / sizeof (int));
}

void TestOP() {
    srand(time(0));
    const int N = 10000;
    int *a1 = (int *) malloc(sizeof(int) * N);
    int *a2 = (int *) malloc(sizeof(int) * N);
    int *a3 = (int *) malloc(sizeof(int) * N);
    int *a4 = (int *) malloc(sizeof(int) * N);
    int *a5 = (int *) malloc(sizeof(int) * N);
    int *a6 = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        a1[i] = rand();
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
    }
    int begin1 = clock();
    InsertSort(a1, N);
    int end1 = clock();
    int begin2 = clock();
    ShellSort(a2, N);
    int end2 = clock();
//    int begin3 = clock();
//    //SelectSort(a3, N);
//    int end3 = clock();
//    int begin4 = clock();
//    //HeapSort(a4, N);
//    int end4 = clock();
//    int begin5 = clock();
//    //QuickSort(a5, 0, N - 1);
//    int end5 = clock();
//    int begin6 = clock();
//    MergeSort(a6, N);
//    int end6 = clock();
    printf("InsertSort:%d\n", end1 - begin1);
    printf("ShellSort:%d\n", end2 - begin2);
//    printf("SelectSort:%d\n", end3 - begin3);
//    printf("HeapSort:%d\n", end4 - begin4);
//    printf("QuickSort:%d\n", end5 - begin5);
//    printf("MergeSort:%d\n", end6 - begin6);
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
}

int main()
{
    //TestInsertSort();
    //TestShellSort();
    //TestOP();
    //TestQuickSort();
    //TestQuickSortNonR();
    //TestMergeSort();
    TetsCountSort();
    return 0;
}

