#include "game.h"
void game(){
    //�洢���� - ��ά����
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    char strategy[ROWS][COLS];
    //��ʼ������ - ��ʼ���ո�
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,' ');
    InitBoard(strategy,ROWS,COLS,'-');
    //��ӡ���� - �����Ǵ�ӡ���������
    //Displayboard(mine,ROW,COL);
    Displayboard_show(show,ROW,COL);

    //������
    SetMine(mine,ROW,COL);
    //Displayboard_mine(mine,ROW,COL);

    //�Ų���
    FindMine(mine,show,strategy,ROW,COL);
}

void menu(){
    int i = 0;
    for(i=1;i<=11;i++) {
        color(13);
        printf("*");
        color(16);
        printf("*");
    }
    printf("\n");
    for(i=1;i<=1;i++){color(16);
        printf("*");
        color(13);
        printf("*");}
    color(16);
    printf("*");
    printf("     1.PLAY     ");
    for(i=1;i<=1;i++){color(13);
        printf("*");
        color(16);
        printf("*");}
    color(13);
    printf("*");
    printf("\n");
    for(i=1;i<=1;i++){color(16);
        printf("*");
        color(13);
        printf("*");}
    color(16);
    printf("*");
    printf("     0.EXIT     ");
    for(i=1;i<=1;i++){color(13);
        printf("*");
        color(16);
        printf("*");}
    color(13);
    printf("*");
    printf("\n");
    for(i=1;i<=11;i++) {
        color(13);
        printf("*");
        color(16);
        printf("*");
    }
    printf("\n");
    color(16);
}
int main(){
    //system("color 9F");
    setbuf(stdout,NULL);
    int input = 0;
    char aga;
    char *str1="Y";
    int test = 0;
    srand((unsigned)time(NULL));
    do{
        menu();
        do{
            printf("��ѡ��");
            scanf("%d",&input);

            switch (input) {
                case 1:
                    printf("\nɨ����Ϸ\n");
                    game();
                    break;
                case 0:
                    printf("\n�˳���Ϸ\n");
                    return 0;
                default:{
                    printf("\nѡ���������ѡ��\n");
                    test = 3;
                    break;}
            }
        }while(test == 3);

        printf("\nagain?(Y/N)");
        scanf("%s",&aga);
    }
    while(strcmp(&aga,str1)==0);
}

//�ݹ�(��ը��ʽ)