#include "game.h"
void game(){
    //�洢���� - ��ά����
    char board[ROW][COL];
    //��ʼ������ - ��ʼ���ո�
    InitBoard(board,ROW,COL);
    //��ӡ���� - �����Ǵ�ӡ���������
    Displayboard(board,ROW,COL);

    char ret = 0;//������Ϸ״̬
    while(1) {
        //�����
        PlayerMove(board, ROW, COL);
        printf("\n");
        //Displayboard(board, ROW, COL);
        //�ж�����Ƿ�Ӯ����Ϸ
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
            break;
        //������
        ComputerMove(board, ROW, COL);
        Displayboard(board, ROW, COL);
        //�жϵ����Ƿ�Ӯ����Ϸ
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
            break;
    }
    printf("\n");
    printf("\n");
    Displayboard(board, ROW, COL);
    printf("\n");
    printf("\n");
    printf("**********");
    printf("**********");
    if(ret == '$')
        printf("\n!!!!  YOU WIN  !!!!\n");
    else if(ret == '#')
        printf("\n====  YOU LOSE  ==== \n");
    else
        printf("\n-----  DRAW  -----\n");
    printf("**********");
    printf("**********");
    printf("\n");
    printf("\n");


}

void menu(){
    printf("**********************\n");
    printf("***     1.PLAY     ***\n");
    printf("***     0.EXIT     ***\n");
    printf("**********************\n");
}
int main(){
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
                    printf("\n��������Ϸ\n");
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

        printf("again?(Y/N)");
        scanf("%s",&aga);
    }
    while(strcmp(&aga,str1)==0);
}