#include "stdio.h"
int main(){
    int a[] = {1,2,3,4,5};
    int b[] = {2,3,4,5,6};
    int c[] = {3,4,5,6,7};

    int* arr[] = {a,b,c};
    int i;
    int j;
    for(i = 0;i < 3;i++){
        for(j = 0;j < 5;j++){
            printf("%d ",arr[i][j]);
            // == printf("%d ",(arr[i]+j));
            //�е����ά���鵫�Ƕ�ά����������������ڴ��У���������������Ƕ���������ڴ��е�
        }
        printf("\n");
    }
    return 0;
}