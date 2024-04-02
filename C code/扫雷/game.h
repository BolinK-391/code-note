//头文件的包含
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "windows.h"

//符号的定义
#define  ROW 16
#define  COL 16
#define  ROWS  ROW+6
#define  COLS  COL+6
#define  EASY_COUNT 10

//函数的声明

//初始化棋盘的
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
//打印棋盘的函数
void Displayboard_mine(char board[ROWS][COLS],int row,int col);
void Displayboard_show(char board[ROWS][COLS],int row,int col);
//布置雷
void SetMine(char mine[ROWS][COLS],int row,int col);
//排查雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],char strategy[ROWS][COLS],int row,int col);
//返回雷的个数
//static int get_mine_count(char mine[ROWS][COLS],int x,int y);
//由于该函数仅仅为支持FindMine函数(楼上)而实现的
//所以不需要报到头文件game.h上去
//ststic关键字符修饰函数的时候，让该函数只能在自己所在的源文件内部看得到

//static
//1.修饰局部变量
//2.修饰全局变量
//3.修饰函数

void color(const unsigned short textColor);


//笔记
//for循环结构前面的条件一必须要=0，即使前面开头已经格式化过了也要=0（格式化）。
//因为for嵌套中，外层再进去的时候内层不格式化就会出现直接从条件二开始的错误情况。

#ifndef UNTITLED1_GAME_H
#define UNTITLED1_GAME_H

#endif //UNTITLED1_GAME_H