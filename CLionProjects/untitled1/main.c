#include<stdio.h>
void bubble_sort(int arr[],int sz){
    //int sz = sizeof (arr)/sizeof (arr[0]);
    for(int i=0;i<sz-1;i++){
        for(int j=0;j<sz-1-i;j++){
            if(arr[j]>arr[j+1]){
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}
//数组名是数组首元素的地址，但是有两个例外
//sizeof（数组名）和&数组名 都表示整个数组，取出的是整个数组的地址
int main(){
    int arr[3];
    for(int i=0;i<3;i++){
        scanf("%d",&arr[i]);}
    //int *p=arr;
    int sz = sizeof (arr)/sizeof (arr[0]);
    bubble_sort(arr,sz);
    for(int i=0;i<3;i++){
        printf("%d\t",arr[i]);
        //p++;
    }
}
