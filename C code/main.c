#include "stdio.h"
#include "math.h"
 //���0~100000֮�������"ˮ�ɻ���"�������
 //"ˮ�ɻ���"��ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
 //�磺153 = 1^3 + 5^3 + 3^3,��153��һ��"ˮ�ɻ���"��

 int main(){
    int i = 0;
    //�ж�i�Ƿ��������
    for(i = 0;i <= 100000;i++){
        //����i��λ�� - n
        int n = 1;
        int tmp = i;
        while(tmp / 10){
           n++;
           tmp = tmp / 10;
        }
        //����i��ÿһλ��n�η�֮��
        tmp = i;
        int sum = 0;
        while(tmp){
            sum += pow(tmp%10,n);//��tmp%10��n�η�
            //pow������η�
            tmp = tmp / 10;
        }
        //�ж�
        if(sum == i)
            printf("%d\n",i);

    }
}