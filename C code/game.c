#include "game.h"
void game(){
    //存储数据 - 二维数组
    char board[ROW][COL];
    //初始化棋盘 - 初始化空格
    InitBoard(board,ROW,COL);
    //打印棋盘 - 本质是打印数组的内容
    Displayboard(board,ROW,COL);

    char ret = 0;//接收游戏状态
    while(1) {
        //玩家走
        PlayerMove(board, ROW, COL);
        printf("\n");
        //Displayboard(board, ROW, COL);
        //判断玩家是否赢得游戏
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
            break;
        //电脑走
        ComputerMove(board, ROW, COL);
        Displayboard(board, ROW, COL);
        //判断电脑是否赢得游戏
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
        printf("请选择：");
        scanf("%d",&input);

            switch (input) {
                case 1:
                    printf("\n井字棋游戏\n");
                    game();
                    break;
                case 0:
                    printf("\n退出游戏\n");
                    return 0;
                default:{
                    printf("\n选择错误，重新选择\n");
                    test = 3;
                    break;}
            }
        }while(test == 3);

        printf("again?(Y/N)");
        scanf("%s",&aga);
    }
    while(strcmp(&aga,str1)==0);
}