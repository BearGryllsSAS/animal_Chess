#include "Animal chess.h"
#include "view.h"
#include "service.h"

/*
	��ʾ�غ���	ż����ʾ�췽	������ʾ����
	eg:flag=10	��ʾ��ǰ�ǵ�11�غ�	�ɺ췽����
*/
int flag;

/*
	��ʾ�غ�ʱ��	��ʼΪ30s	ÿһ�غϿ�ʼ��ʱ������
*/
int roundTime;

/*
	��ʾ��ƽ�غ���	���м����ӱ���	��ƽ�غ�������
	��ƽ�غ����ﵽ20���ᴥ������	�˺�һֱ��������
	eg:peaceFlag=19	��ƽ	peaceFlag=20 ��������
*/
int peaceFlag;

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
int map[4][4];

/*
	����������
		�о������е����ӵ�ֵ
		���㸳ֵ
*/
vector<int> animal = { 11,12,13,14,15,16,17,18,21,22,23,24,25,26,27,28 };

/*
	������������
		�����ж�ʤ��
		��deathCountxxx==8��ʱ�����Ϊ����
*/
int deathCountRed, deathCountBlue;

/*
	��Ϣ����
		���ڽ��������Ϣ
*/
ExMessage msg;


/*
	��¼����Ƿ��ǵ�һ�Σ���¼��һ�Σ��ڶ��ε�����
*/
bool isFirstClick = true;
int firstRow, firstCol, secondRow, secondCol;
bool back_to_main=false;
bool stop = false;
bool music_on = true;
int round_Times = 30;


string currentPage="main";
int main()
{
	
	menuView();	
	return 0;
}
