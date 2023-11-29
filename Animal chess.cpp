#include "Animal chess.h"
#include "view.h"
#include "service.h"

/*
	表示回合数	偶数表示红方	奇数表示蓝方
	eg:flag=10	表示当前是第11回合	由红方下棋
*/
int flag;

/*
	表示回合时长	起始为30s	每一回合开始的时候重置
*/
int roundTime;

/*
	表示和平回合数	若中间棋子被吃	和平回合数重置
	和平回合数达到20将会触发火灾	此后一直产生火灾
	eg:peaceFlag=19	和平	peaceFlag=20 触发火灾
*/
int peaceFlag;

/*
	棋盘：
	map[i][j]表示棋盘上(i,j)坐标点是什么
	0表示此地为空，1表示未翻的棋子，2表示此地有火，
	十位数上的1表示红方的棋子，2表示蓝方的棋子，个位数上的1~8表示不同的动物:
	1表示鼠，2表示猫，3表示狗，4表示狼，5表示豹，6表示虎，7表示狮，8表示象
	例子： 
	map[1][1]=0 表示(1,1)坐标上没有任何棋子
	map[2][1]=1 表示(2,1)坐标上的棋子还未被翻
	map[2][2]=2 表示(2,2)坐标上有火
	map[3][2]=12 表示(3,2)坐标上的棋子是红方的猫
*/
int map[4][4];

/*
	棋子容器：
		列举了所有的棋子的值
		方便赋值
*/
vector<int> animal = { 11,12,13,14,15,16,17,18,21,22,23,24,25,26,27,28 };

/*
	棋子死亡数：
		用于判断胜负
		当deathCountxxx==8的时候就判为输了
*/
int deathCountRed, deathCountBlue;

/*
	消息处理：
		用于接收鼠标信息
*/
ExMessage msg;


/*
	记录点击是否是第一次，记录第一次，第二次的坐标
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
