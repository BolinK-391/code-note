//头文件的包含
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//符号的定义
#define  ROW 3
#define  COL 3

//函数的声明

//初始化棋盘的
void InitBoard(char board[ROW][COL],int row,int col);
//打印棋盘的函数
void Displayboard(char board[ROW][COL],int row,int col);
//玩家下棋
void PlayerMove(char board[ROW][COL],int row,int col);
//电脑下棋
void ComputerMove(char board[ROW][COL],int row,int col);
//判断胜负
//'$' - 玩家赢
//'#' - 电脑赢
//'Q' - 平局
//'C' - 游戏继续
char IsWin(char board[ROW][COL],int row,int col);

//笔记
//for循环结构前面的条件一必须要=0，即使前面开头已经格式化过了也要=0（格式化）。
//因为for嵌套中，外层再进去的时候内层不格式化就会出现直接从条件二开始的错误情况。

#ifndef UNTITLED1_GAME_H
#define UNTITLED1_GAME_H

#endif //UNTITLED1_GAME_H
