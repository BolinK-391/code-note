#include "game.h"

//如何直接跳出深层递归而不是一层一层跳出?
//假设可以忽略各层递归的中间状态! 那么使用递归的意义又何在直接用循环好了!
//如果需要考虑递归的中间状态! 那么为什么要直接退到最外层?
//实际工作中是要避免使用递归! 因为递归都能拆成循环! 递归效率太低!

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set){
    int i = 0;
    int j = 0;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            board[i][j] = set;
        }
    }
}

void Displayboard_mine(char board[ROWS][COLS],int row,int col){
    int i = 0;
    color(14);
    printf("0");
    for(i=1;i<=9;i++){
        color(14);
        printf("  %d   ",i);
    }
    printf("\n");
    for (i=8;i<=row;i++){{
        color(14);
        printf("%d",i-7);
    }
        int j = 0;
        for(j=8;j<=col;j++){
            if(board[i][j] == '1')color(4);
            else color(16);
            printf("  %c  ",board[i][j]);
            if(j<col){
                color(16);
                printf("|");}
        }
        printf("\n");
        printf(" ");
        for(j=8;j<=col;j++){
            color(16);
            printf("-----");
            if(j<col){
                color(16);
                printf("|");}
        }
        printf("\n");

    }
}

void Displayboard_show(char board[ROWS][COLS],int row,int col){
    int i = 0;
    color(14);
    printf("0");
    for(i=1;i<=9;i++){
        color(14);
        printf("  %d   ",i);
    }
    printf("\n");
    for (i=8;i<=row;i++){{
            color(14);
            printf("%d",i-7);
        }
        int j = 0;
        for(j=8;j<=col;j++){
            if(board[i][j] == '1')color(11);
            else if(board[i][j] == '2')color(3);
            else if(board[i][j] == '3')color(13);
            else if(board[i][j] == '4')color(4);
            else if(board[i][j] == '5')color(1);
            else if(board[i][j] == '%')color(6);
            else if(board[i][j] == '/')color(8);
            else color(16);
            printf("  %c  ",board[i][j]);
            if(j<col){
                color(16);
                printf("|");}
        }
        printf("\n");
        printf(" ");
        for(j=8;j<=col;j++){
            color(16);
            printf("-----");
            if(j<col){
                color(16);
                printf("|");}
        }
        printf("\n");

    }
}


void SetMine(char mine[ROWS][COLS],int row,int col){
    //布置10个雷
    int count = EASY_COUNT;
    while(count){

        //生成随即下标
        int x = rand() % 8 + 9;
        int y = rand() % 8 + 9;
        //printf("\n%d%d\n",x,y);
        if(mine[x][y] == '0'){
            mine[x][y] = '1';
            count -- ;
        }

    }
    int i = 0;
    int j = 0;
//    for(i=0;i<ROW;i++)
//    {
//        for(j=0;j<COL;j++){
//    if(mine[i][j] == '1')color(4);
//    else color(16);
//        }
//}
}


void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],char strategy[ROWS][COLS],int row,int col) {
    //1.输入排查的坐标
    //2.检查坐标处是不是雷
    //(1)是雷    - 很遗憾炸死了 - 游戏结束
    //(2)不是雷   - 统计坐标周围有几个雷 - 存储排查雷的信息到show数组，游戏继续
    void get_mine_count(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//开头声明函数(没有使用)
    int x = 0;
    int y = 0;
    int win = 0;
    int digx = 0;
    int digy = 0;
    int chance = EASY_COUNT;
    while (win < EASY_COUNT) {

        printf("Search:");
        scanf("%1d%1d", &x, &y);
        x = x + 7;
        y = y + 7;

        if (show[x][y] == '%') printf("\nNO,Cancel first\n\n");
        else {
            //判断坐标的合法性
            if (x >= 8 && x <= row && y >= 8 && y <= col) {

                if (mine[x][y] == '1') {
                    Sleep(500);
                    printf("\n\n!!!!  BOOM  !!!!\n");
                    printf("\n!!!!  BOOM  !!!!\n");
                    printf("\n!!!!  BOOM  !!!!\n\n");
                    Sleep(1000);
                    printf("\n====  YOU LOSE  ==== \n\n");
                    Sleep(1000);
                    Displayboard_mine(mine, row, col);
                    break;
                }
                else if(show[x][y] != ' '){
                    printf("\ndid it before , reenter\n\n");
                    continue;
                }

                    //不是雷情况下，统计下x,y坐标周围有几个雷
                else get_mine_count(mine, show, x, y);


                //因为show数组存储的是字符类型而a是整型变量，
                // 所以要用ASCII表得出'0' - 48(ASCII码)  '1' - 49(ASCII码) ...



                //显示排查出的信息
                Displayboard_show(show, row, col);
                while (chance != 0) {
                    printf("dig(Enter 00 to skip):");
                    scanf("%1d%1d", &digx, &digy);
                    digx = digx + 7;
                    digy = digy + 7;

                    if (digx >= 8 && digx <= row && digy >= 8 && digy <= col) {
                        if (show[digx][digy] != ' ') printf("\nOccupy\n\n");

                        else  {
                            show[digx][digy] = '%';
                            strategy[digx][digy] = '1';
                            Displayboard_show(show,ROW,COL);
                            chance --;
                            if (strategy[digx][digy] == mine[digx][digy])
                                win++;
                            //printf("%d",win);
                            break;

                        }
                    }
                    else if(digx == 7 && digy == 7)break;

                }
                if (chance == 0)
                    printf("\nFULL , please cancel one\n");

                int canx = 0;
                int cany = 0;
                while(chance != EASY_COUNT) {
                    printf("Cancel Something(Enter 00 to skip):");
                    scanf("%1d%1d", &canx, &cany);
                    canx = canx + 7;
                    cany = cany + 7;
                    if (canx != 7 && cany != 7) {
                        if (show[canx][cany] == '%')
                        {
                            show[canx][cany] = ' ';
                            Displayboard_show(show,ROW,COL);
                            chance ++;
                            if(strategy[canx][cany] == mine[canx][cany]) { win--; }
                            //printf("%d",win);
                            break;
                        }
                    }
                    else if(canx == 7 && cany == 7) break;
                    else printf("No dig , again?");
                }
                }

             else printf("Try again\n");
        }
    }



    if(win == EASY_COUNT){
        Sleep(500);
        printf("\n\n////  OMG  ////\n");
        printf("\n////  OMG  ////\n");
        printf("\n////  OMG  ////\n\n");
        Sleep(1000);
        printf("\n!!!!  YOU WIN  !!!!\n\n");
        Sleep(1000);
        Displayboard_mine(mine,row,col);

    }
}


void get_mine_count(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y) {

            int num = 0;
            int xx = 0;
            int yy = 0;
            int i = 0;
            int j = 0;
            int b = 0;
            for (i = -1; i <= 1; i++) {
                for (j = -1; j <= 1; j++)
                    if (i == 0 && j == 0) { continue; }
                    else b += mine[x + i][y + j];
            }
            num = b - 8 * '0';
            if (num != 0) {
                show[x][y] = num + '0';
            } else {
                show[x][y] = '/';
                int s = 0;
                int t = 0;
                for (s = 1; s < EASY_COUNT; s++) {

                    for (xx = -s; xx <= s; xx++) {
                        for (yy = -s; yy <= s; yy++) {
                            if (xx == 0 && yy == 0) { continue; }
                            b = 0;
                            for (i = -1; i <= 1; i++) {
                                for (j = -1; j <= 1; j++)
                                    if (i == 0 && j == 0) { continue; }
                                    else b += mine[x + xx + i][y + yy + j];
                                num = b - 8 * '0';
                            }
                            if (num != 0) {
                                show[x + xx][y + yy] = num + '0';
                                t++;
                            }
                        }
                    }

                    if (t != 0)break;
                }
            }
        }

void color(const unsigned short textColor)      //自定义函根据参数改变颜色
{
    if(textColor>=0 && textColor<=15)     //参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //用一个参数，改变字体颜色
    else   //默认的字体颜色是白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}