#include "stdio.h"
//����ָ�������Ӧ��
//������ - �������ͱ����ļӡ������ˡ���

int Add(int x,int y){
    return x+y;
}
int Sub(int x,int y){
    return x-y;
}
int Mul(int x,int y){
    return x*y;
}
int Div(int x,int y){
    return x/y;
}

int main(){
    int input = 0;
    do{
        int x = 0;
        int y = 0;
        int ret = 0;
        printf("��ѡ�����");
        scanf("%d",&input);
        int (*pfArr[5])(int,int) = {NULL,Add,Sub,Mul,Div};
        //����ָ������
        if(input >= 1 && input <=4){
        printf("��ѡ�����֣�");
        scanf("%d %d",&x,&y);
        ret = (pfArr[input])(x,y);
        printf("ret = %d\n",ret);
        }
        else if(input == 0) break;
        else
            ;

    }while(input);
    return 0;
}