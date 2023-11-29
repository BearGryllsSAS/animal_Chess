#include"Animal chess.h"
#include"service.h"
//--------------view---------------

void ak_button(int x, int y, int w, int h, TCHAR* text);
void ak_button_2(int x, int y, int w, int h, const char* text);
void ak_button_music(int x, int y, int w, int h, const char* text, bool judge);
bool inArea(int mx, int my, int x, int y, int w, int h);
void button(int x, int y, int w, int h, TCHAR* text); //输入坐标，宽度，字符串实现框框

/*
	负责人：小光
	功能：
		展示以下选项：
			开始游戏
			设置
			玩法介绍
			关于我们
			退出游戏
		通过鼠标点击确认

		开始游戏:gameView();
		设置:setView();
		玩法介绍:introduceView();
		关于我们:aboutView();
		退出游戏:exit(0);
	参数：void
	返回值：void
*/
void menuView();

/*
	负责人：憨憨
	功能：
		游戏功能：
			初始化游戏数据(调用init())
			while(1)
			{
				展示各游戏按键（调用showButton()）
				展示游戏棋盘（调用gameView_ShowMap()）

				if(超过20回合没有棋子被吃)	生成火（调用fire()）

				开始回合倒计时（调用countDown()）
				并进行展示（调用timeView()）

				接收玩家鼠标信息——翻棋（调用turnChess()）/移棋（调用playerMove()）/认输（调用winView()，同时退出循环）
				/暂停（调用stopView()）
				（如果时间超过了roundTime则调用winView(),判对方胜利，退出循环）
				（如果涉及到各界面的转换，都需要重新展示游戏界面
				  比如暂停后调用了暂停界面，取消暂停后需要重新展示游戏界面）

				判断游戏是否结束（调用isWin()）
				 （如果胜利，调用winView(),结束当前画面,返回主菜单(调用returnMenu())）

				切换玩家（修改flag、peaceFlag）
			}
	参数：void
	返回值：void
*/
void gameView();

/*
	负责人：曹
	功能：
		展示以下选项：
			音乐
			游戏速度调节	1~5等级
			皮肤选择
			返回主菜单(调用returnMenu())
		通过鼠标点击确认

		音乐:musicView();
		速度调节、皮肤选择的选项就直接显示
	参数：int x,int y
		表示鼠标点击的位置
	返回值：bool
		0	表示未点击
		1	表示点击
*/
void setView();

/*
	负责人：charlottee
	功能：
		展示以下功能：
			音乐选择
			音量调节	1~5等级
			音乐开关
			返回设置界面
		通过鼠标点击确认

	参数：int x,int y
		表示鼠标点击的位置
	返回值：bool
		0	表示未点击
		1	表示点击
*/
void musicView();

/*
	负责人：Ginko
	功能：
		展示以下选项：
			规则玩法介绍
			返回主菜单(调用returnMenu())
		通过鼠标点击确认
	参数：void
	返回值：void
*/
void introduceView();

/*
	负责人：汪
	功能：
		展示以下选项：
			团队、开发等介绍
			返回主菜单(调用returnMenu())
		通过鼠标点击确认
	参数：void
	返回值：void
*/
void aboutView();

/*
	负责人：阿门
	功能：
		展示暂停界面
		返回主菜单(调用returnMenu())

		需要写一个死循环，为了取消暂停时，能继续计时
	参数：void
	返回值：void
*/
void stopView();

/*
	负责人：阿豪
	功能：
		展示胜利界面
		返回主菜单(调用returnMenu())
	参数：void
	返回值：void
*/
void winView();

/*
	负责人：憨憨
	功能：
		根据map数组	打印棋盘
		同时根据具体的值  打印棋子
	参数：void
	返回值：void
*/
void gameView_ShowMap();

/*
	负责人：莫一
	功能：
		展示倒计时
		根据全局变量roundTime打印剩余回合时间
	参数：void
	返回值：void
*/
void timeView();

/*
	负责人：阿豪
	功能：
		返回主菜单
		(很多界面都需要返回主菜单，单独封装成一个函数)
	参数：int x,int y
		表示鼠标点击的位置
	返回值：int
		0	表示未点击
		1	表示点击并返回主菜单
*/

void returnMenu();



//--------------view---------------