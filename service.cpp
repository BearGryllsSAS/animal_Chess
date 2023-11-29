#include "service.h"

void init()
{
	animal = { 11,12,13,14,15,16,17,18,21,22,23,24,25,26,27,28 };
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			map[i][j] = 1;	
	}
	flag = 0;
	roundTime = round_Times;
	deathCountBlue = 0;
	deathCountRed = 0;
}

void turnChess(int x, int y) {
	// 根据传入的合法的坐标 (x,y) 判断该位置是否为未翻棋状态，如果不是则不执行 if ，直接返回
	if (map[x][y] == 1) {
		// 设置随机数种子
		srand((unsigned)time(NULL));

		// 随机获取 animal 的下标，将 animal 中对应下标的元素赋值给map地图 
		int index = rand() % animal.size();
		map[x][y] = animal[index];

		// 将 animal 中对应下标的元素删除
		animal.erase(animal.begin() + index);
		flag++;
		roundTime = round_Times;
		PlaySound(TEXT("./bgm/kill.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return;
	}

	return;
}
int playerMove(int x, int y, int d_x, int d_y) {
	// 判断选中的位置的棋子是否可以移动，不可以直接返回 0
	if (isMove(x, y, d_x, d_y) == 1) {
		// (x,y)要为当前回合数对应的 红方/蓝方 已翻开的棋子，(d_x,d_y)要为 空地/敌方已经翻开的棋子------在isMove中已经完成判断
		// 根据传入的要移动的合法的目的地进行判断，如果目的地上为敌方棋子
		if (map[d_x][d_y] > 10) {
			// 获取当前为哪方的回合---红方为ture，蓝方则为false
			//flag =10 红色下棋，round=true
			// 根据食物链关系，判断输赢
			if (map[x][y] % 10 == 8 && map[d_x][d_y] % 10 ==1) {
				// 1是象，2是鼠
				map[x][y] = 0;
				cout << "flag是" << flag << endl;
				if (flag % 2 == 0) { // 1象撞2鼠   红色下棋 红被蓝色吃了
					deathCountRed++;
				}
				else {
					deathCountBlue++;
				}
				flag++;
			}
			else if (map[x][y] % 10 == 1 && map[d_x][d_y] % 10 == 8){
				// 1是鼠，2是象
				map[d_x][d_y] = map[x][y];
				map[x][y] = 0;
				if (flag % 2 == 0) { // 1象撞2鼠   红色下棋 红把蓝色吃了
					deathCountBlue++;
				}
				else {
					deathCountRed++;
				}
				flag++;
			}
			else if (map[x][y] % 10 > map[d_x][d_y] % 10) {
				//排除了鼠象问题，之后就是大的吃小的
				map[d_x][d_y] = map[x][y];
				map[x][y] = 0;

				if (flag % 2 == 0) {
					deathCountBlue++;
				}
				else {
					deathCountRed++;
				}
				flag++;
			}
			else if (map[x][y] % 10 < map[d_x][d_y] % 10) {
				//小的撞到大的
				map[x][y] = 0;

				if (flag % 2 == 0) {
					deathCountRed++;
				}
				else {
					deathCountBlue++;
				}
				flag++;
			}
			else if (map[x][y] % 10 == 8 && map[d_x][d_y] % 10 == 8) {
				//包含双方全为象的情况
				map[x][y] = 0;
				map[d_x][d_y] = 0;

				deathCountRed++;
				deathCountBlue++;
				flag++;
			}
			else if (map[x][y] % 10 == map[d_x][d_y] % 10 ) {
				//同归于尽
				map[x][y] = 0;
				map[d_x][d_y] = 0;

				deathCountRed++;
				deathCountBlue++;
				flag++;
			}
			PlaySound(TEXT("./bgm/kill.wav"), NULL, SND_FILENAME | SND_ASYNC);
			// 和平回合数置零
			peaceFlag = 0;
		}
		else {
			map[d_x][d_y] = map[x][y];
			map[x][y] = 0;
			flag++;

			// 增加和平回合数
			if (peaceFlag < Fire_Max_Flag) {
				peaceFlag++;
			}
			PlaySound(TEXT("./bgm/kill.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		fire();
		roundTime = round_Times;
		
		return 1;
	}

	return 0;
}


int isMove(int x, int y, int d_x, int d_y)
{
	// 判断目标地是否越界
	if (d_x < 0 || d_x >= 4 || d_y < 0 || d_y >= 4)
	{
		return 0;
	}
	// 判断目标地是否为空地
	// 判断目标地是否有火
	if (map[d_x][d_y] == 2   || map[d_x][d_y] == 1)
	{
		return 0;
	}
	// 判断目标地是否有自己的棋子
	if (map[d_x][d_y] / 10 == map[x][y] / 10)
	{
		return 0;
	}
	// 判断是否可以移动到目标地
	int dx = abs(d_x - x);
	int dy = abs(d_y - y);
	if (dx + dy != 1)
	{
		return 0;
	}

	return 1;
}





void fire()
{

	if (peaceFlag >= Fire_Max_Flag)                         //判断要求是否成立
	{

		bool judge = false;                             //构建一个vector数组存储位置为0的地方
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[i][j] == 0)
					judge = true;
			}
		}
		if (judge)//有空地可以着火
		{
			while (true)
			{
				int x = rand() % 4;
				int y = rand() % 4;
				if (map[x][y] == 0)
				{
					map[x][y] = 2;
					return;
				}
			}
		}
		else
			return;
		
	}
}


int isWin()
{
	if (roundTime == 0)
	{
		if (flag % 2 == 1) return 1;
		if (flag % 2 == 0) return 2;
	}

	if (deathCountRed == 8 || deathCountBlue == 8) {//判读是否有死亡8棋子
		if (deathCountRed == 8 && deathCountBlue == 8) {//两个都死亡8，看对局数
			if (flag % 2 == 1) return 1;
			if (flag % 2 == 0) return 2;
		}
		if (deathCountRed == 8) return 2;//其他看哪一方死亡
		else if (deathCountBlue == 8) return 1;
	}
	return 0;
}

void click_chess()
{
	if (peekmessage(&msg, EM_MOUSE)) { // 只检查鼠标消息
		if (msg.message == WM_LBUTTONDOWN) { // 如果此时鼠标左键按下
			int row = msg.y / BlockSide; //对应x的坐标
			int col = msg.x / BlockSide;//对应y的坐标
			//判断map[row][col]的值 
			//cleardevice();//清屏
			if (msg.x >= 400 && msg.y >= 600)
			{
				back_to_main = true;
				return;
			}
			if (msg.x >= 0 && msg.y >= 600&&msg.x<=80&&msg.y<=640)
			{
				stop = true;
				return;
			}
			if (isFirstClick) {
				// 第一次点击
				firstRow = row;
				firstCol = col;
				if (map[row][col] == 0|| map[row][col] == 2)//点到空地或者火地
				{
					return;
				}
				else if (map[row][col] == 1)//点到未被翻开的棋子
				{
					cout << "翻开棋子" << endl;
					turnChess(row, col);
				}
				else if (map[row][col] > 10)//点到翻开的兽的棋子
				{
					int player_flag = map[row][col] / 10;//1是红色的棋子 2是蓝色的棋子
					int player_except_flag = flag % 2;//为0时是红色 为1时是蓝色  假设此时flag是10 第11回合，红方下棋 此时为0
					if (player_flag == (player_except_flag + 1))//点击到自己的棋子
					{
						cout << "第一次点击完成"<<row<<col<<endl;
						isFirstClick = false;//当此次点击达成移动操作后，改变此参数
					}
					else //点的是别人的棋子
					{
						isFirstClick = true;
						return;
					}
				}			
			}
			else {
				// 第二次点击
				secondRow = row;
				secondCol = col;
				cout << "第二点击完成" << row << col << endl;
				playerMove(firstRow, firstCol, secondRow, secondCol);
				//int judge=playerMove(firstRow, firstCol, secondRow, secondCol);
				//if (judge)
					//cout << "移动成功"<<endl;
				cout << deathCountRed <<"_R______B_" << deathCountBlue << endl;
				cout <<"flag:" << flag << " "<< "peace: " << peaceFlag << endl;
				
				// 重置点击状态
				isFirstClick = true;
			}

			
		}
	}

}




