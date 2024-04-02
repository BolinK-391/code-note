#include "game.h"

//���ֱ���������ݹ������һ��һ������?
//������Ժ��Ը���ݹ���м�״̬! ��ôʹ�õݹ�������ֺ���ֱ����ѭ������!
//�����Ҫ���ǵݹ���м�״̬! ��ôΪʲôҪֱ���˵������?
//ʵ�ʹ�������Ҫ����ʹ�õݹ�! ��Ϊ�ݹ鶼�ܲ��ѭ��! �ݹ�Ч��̫��!

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
    //����10����
    int count = EASY_COUNT;
    while(count){

        //�����漴�±�
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
    //1.�����Ų������
    //2.������괦�ǲ�����
    //(1)����    - ���ź�ը���� - ��Ϸ����
    //(2)������   - ͳ��������Χ�м����� - �洢�Ų��׵���Ϣ��show���飬��Ϸ����
    void get_mine_count(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//��ͷ��������(û��ʹ��)
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
            //�ж�����ĺϷ���
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

                    //����������£�ͳ����x,y������Χ�м�����
                else get_mine_count(mine, show, x, y);


                //��Ϊshow����洢�����ַ����Ͷ�a�����ͱ�����
                // ����Ҫ��ASCII��ó�'0' - 48(ASCII��)  '1' - 49(ASCII��) ...



                //��ʾ�Ų������Ϣ
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

void color(const unsigned short textColor)      //�Զ��庯���ݲ����ı���ɫ
{
    if(textColor>=0 && textColor<=15)     //������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //��һ���������ı�������ɫ
    else   //Ĭ�ϵ�������ɫ�ǰ�ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}