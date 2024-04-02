#include "game.h"
void game(){
    //存储数据 - 二维数组
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    char strategy[ROWS][COLS];
    //初始化棋盘 - 初始化空格
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,' ');
    InitBoard(strategy,ROWS,COLS,'-');
    //打印棋盘 - 本质是打印数组的内容
    //Displayboard(mine,ROW,COL);
    Displayboard_show(show,ROW,COL);

    //布置雷
    SetMine(mine,ROW,COL);
    //Displayboard_mine(mine,ROW,COL);

    //排查雷
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
            printf("请选择：");
            scanf("%d",&input);

            switch (input) {
                case 1:
                    printf("\n扫雷游戏\n");
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

        printf("\nagain?(Y/N)");
        scanf("%s",&aga);
    }
    while(strcmp(&aga,str1)==0);
}
//比较两个字符串相等 不能使用 ==
//递归(呈炸开式)
