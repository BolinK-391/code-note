//ͷ�ļ��İ���
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "windows.h"

//���ŵĶ���
#define  ROW 16
#define  COL 16
#define  ROWS  ROW+6
#define  COLS  COL+6
#define  EASY_COUNT 10

//����������

//��ʼ�����̵�
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
//��ӡ���̵ĺ���
void Displayboard_mine(char board[ROWS][COLS],int row,int col);
void Displayboard_show(char board[ROWS][COLS],int row,int col);
//������
void SetMine(char mine[ROWS][COLS],int row,int col);
//�Ų���
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],char strategy[ROWS][COLS],int row,int col);
//�����׵ĸ���
//static int get_mine_count(char mine[ROWS][COLS],int x,int y);
//���ڸú�������Ϊ֧��FindMine����(¥��)��ʵ�ֵ�
//���Բ���Ҫ����ͷ�ļ�game.h��ȥ
//ststic�ؼ��ַ����κ�����ʱ���øú���ֻ�����Լ����ڵ�Դ�ļ��ڲ����õ�

//static
//1.���ξֲ�����
//2.����ȫ�ֱ���
//3.���κ���

void color(const unsigned short textColor);


//�ʼ�
//forѭ���ṹǰ�������һ����Ҫ=0����ʹǰ�濪ͷ�Ѿ���ʽ������ҲҪ=0����ʽ������
//��ΪforǶ���У�����ٽ�ȥ��ʱ���ڲ㲻��ʽ���ͻ����ֱ�Ӵ���������ʼ�Ĵ��������

#ifndef UNTITLED1_GAME_H
#define UNTITLED1_GAME_H

#endif //UNTITLED1_GAME_H