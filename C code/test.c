#include "game.h"
void InitBoard(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            board[i][j] = ' ';
        }
    }
}

void Displayboard(char board[ROW][COL],int row,int col){
    int i = 0;
    for (i;i<row;i++){
        int j = 0;
        for(j;j<col;j++){
        printf("  %c  ",board[i][j]);
        if(j<col-1)
            printf("|");}
        printf("\n");
        for(j=0;j<col;j++){
            printf("-----");
            if(j<col-1)
                printf("|");}
        printf("\n");

    }
}

void PlayerMove(char board[ROW][COL],int row,int col){
    int x = 0;
    int y = 0;
    printf("\nYou($):");
    while(1) {
        scanf("%1d%1d", &x, &y);
        //在%d的d前面加上数字可以有效控制输入数据的宽度
        //判断坐标合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            //下棋
            //判断坐标是否被占用
            if(board[x-1][y-1] == ' '){
                board[x-1][y-1] = '$';
                break;

            }
            else printf("occupy\n");
        }
        else
            printf("Try again\n");
        printf("You($):");
    }
}

void ComputerMove(char board[ROW][COL],int row,int col){
    printf("\nComputer(#):\n");
    while(1) {
        int x = rand() % row;
        int y = rand() % col;

        //判断占用
        if (board[x][y] == ' ') {
            board[x][y] = '#';
            break;
        }
    }
}

int IsFull(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            if(board[i][j]==' '){
                return 0;}//棋盘没满
        }
    }
    return 2;//棋盘满了
}

char IsWin(char board[ROW][COL],int row,int col){
    int i = 0;
    //判断三行
    for (i=0;i<row;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]!=' ')
        return board[i][1];
    }
    //判断三列
    for (i=0;i<col;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i]!=' ')
        return board[1][i];
    }
    //判断对角线
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=' ')
        return board[1][1];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!=' ')
        return board[1][1];
    //判断平局
    //如果棋盘满了返回1，不满返回0
    int ret = IsFull(board,row,col);
    if(ret == 2)
        return 'Q';
    else
        return 'C';
}