#include "stdio.h"
//�ص�������Ӧ��
//������ - �������ͱ����ļӡ������ˡ���

void Calc(int (*pf)(int,int))//�ص�����������Ĳ����Ǻ���ָ�룩
{
    int x = 0;
    int y = 0;
    printf("��ѡ�����֣�");
    scanf("%d %d",&x,&y);
    int ret = 0;
    ret = pf(x,y);//ͨ��pf����Add����
    printf("ret = %d\n",ret);
}

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

        int ret = 0;
        printf("��ѡ�����");
        scanf("%d",&input);
        switch (input) {
            case 1:Calc(Add);break;//����Add����ָ��
            case 2:Calc(Sub);break;
            case 3:Calc(Mul);break;
            case 4:Calc(Div);break;
        }

    }while(input);
    return 0;
}

//�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ��������
//�����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص�������
//�ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ��