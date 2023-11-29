#include "Animal chess.h"
//------------service-------------

/*
	负责人：曹
	功能：
		初始化游戏数据
		均赋值为1，表示棋盘上均是未翻的棋
		当前回合是红方（flag设为0）
		和平回合数开始累计（peaceFlag设为1）
		棋子死亡数重置(deathCount设为0)
		重置棋子容器
	参数：void
	返回值：void
*/
void init();

/*
	负责人：莫一
	功能：
		将选中的未翻的棋子进行翻转
		根据回合数进行赋值（11~18 or 21~28）
		同时将容器中相应的值pop
	参数：int x,int y
		表示选择翻的棋子的坐标
	返回值：void
*/
void turnChess(int x, int y);

/*
	负责人：小光
	功能：
		移动选中的棋子
		进行判断能否移动（调用isMove()）
		可以移动则进行坐标修改及棋盘相应坐标上的值的改变
		否则不做处理
		若有棋子被吃，死亡数deathCountxxx++,同时修改peaceFlag
		（注意peaceFlag若达到20	则不能修改）
	参数：int x,int y,int d_x,int d_y
		x,y表示选择移动的棋子的坐标
		d_x,d_y表示目标地的坐标
	返回值：int
		0	表示移动失败
		1	表示移动成功
*/
int playerMove(int x,int y,int d_x,int d_y);

/*
	负责人：charlottee
	功能：
		进行判断是否可以移动
	参数：int x,int y,int d_x,int d_y
		x,y表示选择移动的棋子的坐标
		d_x,d_y表示目标地的坐标
	返回值：
		0	表示不能移动
		1	表示能移动
*/
int isMove(int x, int y, int d_x, int d_y);


/*
	负责人：汪
	功能：
		生成火
		判断peaceFlag是否达到20
			达到则随机在没有棋子的地方生成火
	参数：void
	返回值：void
*/
void fire();

/*
	负责人：阿门
	功能：
		根据死亡棋子数deathCount判断是否胜利
		同时根据flag判断谁胜利(出现同时死的情况)
	参数：void
	返回值：int
		0	表示没有结束
		1	表示红方胜利
		2	表示蓝方胜利
*/
int isWin();
/*
负责人：阿康
功能：处理鼠标的点击事件,初始click_state为1，是第一次点击
		循环调用isin(int x,int y)判断鼠标点击的棋子是哪一个
		1.鼠标点击的位置，如果没有棋子或者火灾，或者是其他人的棋子continue
		2.如果是未翻面的，把棋子翻过来，换下一个人
		3.如果是翻面的，记录此次点击和下一次点击begin end
		第一次点击后click_state+1,后进行第二次点击，记录第二次点击的坐标end
参数：无
返回值：无
*/
void click_chess();


//------------service-------------