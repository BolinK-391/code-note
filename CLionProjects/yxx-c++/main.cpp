#include <stdio.h>
//����n�Ľ׳�
int main() {
    int i,j=1,z=1;
    scanf("%d",&i);
    for(int num = 1;num<=i;num++){
    //     z = z*num;
    //     j = z ;
    //���д�� ��z����num���ٰѳ���֮������ָ���z��
        z *= num ;

        printf("%d",num);
        if(num == i){
            continue;
        }
        printf("*");
    }
    printf("=%d",z);
    }



