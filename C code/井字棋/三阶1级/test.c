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
        //��%d��dǰ��������ֿ�����Ч�����������ݵĿ��
        //�ж�����Ϸ���
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            //����
            //�ж������Ƿ�ռ��
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

        //�ж�ռ��
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
                return 0;}//����û��
        }
    }
    return 2;//��������
}

char IsWin(char board[ROW][COL],int row,int col){
    int i = 0;
    //�ж�����
    for (i=0;i<row;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]!=' ')
        return board[i][1];
    }
    //�ж�����
    for (i=0;i<col;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i]!=' ')
        return board[1][i];
    }
    //�ж϶Խ���
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=' ')
        return board[1][1];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!=' ')
        return board[1][1];
    //�ж�ƽ��
    //����������˷���1����������0
    int ret = IsFull(board,row,col);
    if(ret == 2)
        return 'Q';
    else
        return 'C';
}