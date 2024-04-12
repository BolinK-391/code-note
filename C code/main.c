#include "stdio.h"
#include "string.h"

//ģ��qsortʵ��һ��ð�������ͨ���㷨
//Ψһ��Ҫ�û��Լ�����ľ��ǱȽϺ������ȽϺ��������ֱ�Ӵ���bubble_sort�����Զ���������
//����ֻ��Ҫ���Լ�����ıȽϺ���cmp����returnǰ��Ե�

int cmp(const void* e1,const void* e2){
    return *(int*)e1 - *(int*)e2;
}

int cmp_char(const void* e1,const void* e2){
    return strcmp((char*)e1,(char*)e2);
}

void Swap(char*e1,char*e2,int width){
    int i = 0;
    for(i = 0;i < width;i++){
        char tmp = *e1;
        *e1 = *e2;
        *e2 = tmp;
        e1++;
        e2++;
    }
}

void bubble_sort(void* base,
                 int sz,
                 int width,
                 int(*cmp)(const void*e1,const void*e2))
{
    int i = 0;
    //����
    for(i = 0 ; i < sz -1;i++ ){
        //һ�˵�����
        int j = 0;
        for(j = 0;j < sz - 1 - i;j++){
            //����Ԫ�رȽ�
            //arr[j] arr[j+1]
            if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0){
                Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
            }
        }
    }
}

void print_arr(char arr[],int sz){
    int i = 0;
    for(i = 0;i <sz;i++){
        printf("%c ",arr[i]);
    }
    printf("\n");
}

int main(){
    char arr[5] = {0};
    int i = 0;
    for(i = 0;i<5;i++){
        scanf("%c",&arr[i]);
        //ע�⣺����Ӧ����%c������д��%s����Ȼ�����޷�����
    }
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,sz,sizeof(arr[0]),cmp_char);
    print_arr(arr,sz);
}


//%c��ʽ��Ӧ���ǵ����ַ���
//%s��ʽ��Ӧ�����ַ�����

//char��char*
//%c��Ӧ����Ϊchar
//%s��Ӧ����Ϊchar * , ���ַ�����

//��������ʱ, ���߲�����Ҫ��char * ��.
//%c���뺯��ֻ���һ���ֽڿռ丳ֵ. ��%s��һֱ��ֵ,ֱ�������������հ��ַ�Ϊֹ.
//�������ʱ, %c��char����,���һ���ַ�. %s��char*���Ͳ���, �����\0Ϊֹ.

//�����ʱ��scanf("%c", &a);�����&������
//��scanf("%s",s);���ﲻ����&����
