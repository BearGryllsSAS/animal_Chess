
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<vector>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include <windows.h> // 包含 Sleep 函数
#include<string>
#include<thread>
#include<chrono>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // 链接到 Windows Multimedia API

/*
	斗兽棋需求文档

	主菜单界面：
		开始游戏
		设置
		玩法介绍
		关于我们
		退出游戏

	游戏界面：
		对局显示
		回合数显示
		悔棋/认输
		翻棋/移棋：
			玩家通过鼠标点击进行翻棋和移棋
		回合倒计时显示	每回合30s
		暂停界面显示
		胜利界面显示
		返回主菜单

	设置界面：
		音乐：
			音乐选择
			音量调节	1~5等级
			音乐开关
			返回设置界面
		游戏速度调节	1~5等级
		皮肤选择
		返回主菜单

	玩法介绍界面：
		规则玩法介绍
		返回主菜单

	关于我们界面：
		团队、开发等介绍
		返回主菜单

	暂停界面：
		继续游戏
		返回主菜单

	胜利界面：
		胜利显示
		返回主菜单

*/

//------------变量设计------------

#define ViewWidth 480//整个画面的宽
#define ViewHeight 640//整个画面的高
#define BlockSide 100//每个格子的大小，正方形
#define Fire_Max_Flag 5//着火的阈值


/*
	表示回合数	偶数表示红方	奇数表示蓝方
	eg:flag=10	表示当前是第11回合	由红方下棋
*/
extern int flag;

/*
	表示回合时长	起始为30s	每一回合开始的时候重置
*/
extern int roundTime;

/*
	表示和平回合数	若中间棋子被吃	和平回合数重置
	和平回合数达到20将会触发火灾	此后一直产生火灾
	eg:peaceFlag=19	和平	peaceFlag=20 触发火灾
*/
extern int peaceFlag;

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
extern int map[4][4];

/*
	棋子容器：
		列举了所有的棋子的值
		方便赋值
*/
extern vector<int> animal;

/*
	棋子死亡数：
		用于判断胜负
		当deathCountxxx==8的时候就判为输了
*/
extern int deathCountRed,deathCountBlue;

/*
	消息处理：
		用于接收鼠标信息
*/
extern ExMessage msg;

//------------变量设计------------

extern bool isFirstClick ;
extern int firstRow, firstCol, secondRow, secondCol;
extern bool back_to_main;
extern bool stop;
extern bool music_on;
extern int round_Times;//30s

extern string currentPage;

