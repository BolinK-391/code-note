#include <stdio.h>
//���������������в�ͬλ�ĸ���
//����int(32λ)����m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ?

int main(){
    int m = 0;
    int n = 0;
    scanf("%d %d",&m,&n);
    int i = 0;
    int count = 0;
    //����һ
    for(i;i < 32;i++){
        if(((m >> i)&1) != ((n >> i)&1))
            count++;
        //((m >> i)&1)�����ַ�ʽȡ���������в�ͬ��λ
    }
    printf("\n%d\n",count);
    //������
    int two(int * m,int * n);
    int count_2 = two(&m,&n);
    printf("\n%d\n",count_2);

    return 0;
}

//������
int two(int * m,int * n){
    int count = 0;
    int ret = *m^*n;//��ͬΪ0,����Ϊ1
//ͳ��һ��ret�Ķ��������м���1����˵��m��n�Ķ�����λ���м���λ��ͬ
    while(ret){
        ret = ret & (ret-1);
        count++;
    }
    return count;
}