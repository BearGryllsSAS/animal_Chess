
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<vector>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include <windows.h> // ���� Sleep ����
#include<string>
#include<thread>
#include<chrono>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // ���ӵ� Windows Multimedia API

/*
	�����������ĵ�

	���˵����棺
		��ʼ��Ϸ
		����
		�淨����
		��������
		�˳���Ϸ

	��Ϸ���棺
		�Ծ���ʾ
		�غ�����ʾ
		����/����
		����/���壺
			���ͨ����������з��������
		�غϵ���ʱ��ʾ	ÿ�غ�30s
		��ͣ������ʾ
		ʤ��������ʾ
		�������˵�

	���ý��棺
		���֣�
			����ѡ��
			��������	1~5�ȼ�
			���ֿ���
			�������ý���
		��Ϸ�ٶȵ���	1~5�ȼ�
		Ƥ��ѡ��
		�������˵�

	�淨���ܽ��棺
		�����淨����
		�������˵�

	�������ǽ��棺
		�Ŷӡ������Ƚ���
		�������˵�

	��ͣ���棺
		������Ϸ
		�������˵�

	ʤ�����棺
		ʤ����ʾ
		�������˵�

*/

//------------�������------------

#define ViewWidth 480//��������Ŀ�
#define ViewHeight 640//��������ĸ�
#define BlockSide 100//ÿ�����ӵĴ�С��������
#define Fire_Max_Flag 5//�Ż����ֵ


/*
	��ʾ�غ���	ż����ʾ�췽	������ʾ����
	eg:flag=10	��ʾ��ǰ�ǵ�11�غ�	�ɺ췽����
*/
extern int flag;

/*
	��ʾ�غ�ʱ��	��ʼΪ30s	ÿһ�غϿ�ʼ��ʱ������
*/
extern int roundTime;

/*
	��ʾ��ƽ�غ���	���м����ӱ���	��ƽ�غ�������
	��ƽ�غ����ﵽ20���ᴥ������	�˺�һֱ��������
	eg:peaceFlag=19	��ƽ	peaceFlag=20 ��������
*/
extern int peaceFlag;

/*
	���̣�
	map[i][j]��ʾ������(i,j)�������ʲô
	0��ʾ�˵�Ϊ�գ�1��ʾδ�������ӣ�2��ʾ�˵��л�
	ʮλ���ϵ�1��ʾ�췽�����ӣ�2��ʾ���������ӣ���λ���ϵ�1~8��ʾ��ͬ�Ķ���:
	1��ʾ��2��ʾè��3��ʾ����4��ʾ�ǣ�5��ʾ����6��ʾ����7��ʾʨ��8��ʾ��
	���ӣ�
	map[1][1]=0 ��ʾ(1,1)������û���κ�����
	map[2][1]=1 ��ʾ(2,1)�����ϵ����ӻ�δ����
	map[2][2]=2 ��ʾ(2,2)�������л�
	map[3][2]=12 ��ʾ(3,2)�����ϵ������Ǻ췽��è
*/
extern int map[4][4];

/*
	����������
		�о������е����ӵ�ֵ
		���㸳ֵ
*/
extern vector<int> animal;

/*
	������������
		�����ж�ʤ��
		��deathCountxxx==8��ʱ�����Ϊ����
*/
extern int deathCountRed,deathCountBlue;

/*
	��Ϣ����
		���ڽ��������Ϣ
*/
extern ExMessage msg;

//------------�������------------

extern bool isFirstClick ;
extern int firstRow, firstCol, secondRow, secondCol;
extern bool back_to_main;
extern bool stop;
extern bool music_on;
extern int round_Times;//30s

extern string currentPage;

