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
            //有点像二维数组但是二维数组是连续存放在内存中，而这个三个数组是独立存放在内存中的
        }
        printf("\n");
    }
    return 0;
}