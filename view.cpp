#include "view.h"

void ak_button(int x, int y, int w, int h, TCHAR* text)
{
	setbkmode(TRANSPARENT);//文字不填充背景色
	setfillcolor(GREEN);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	TCHAR s1[] = _T("Arial BLACK");
	settextstyle(30, 0, s1);
	//settextstyle 设置文本样式，其中第一个参数是字体高度，第二个参数是字体宽度（0 表示自动按比例计算），第三个参数是字体名称。
	settextcolor(WHITE);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void ak_button_2(int x, int y, int w, int h, const char* text)
{
	setbkmode(TRANSPARENT);//文字不填充背景色

	setfillcolor(LIGHTMAGENTA);

	fillroundrect(x, y, x + w, y + h, 10, 10);
	TCHAR s1[] = _T("Arial BLACK");
	settextstyle(30, 0, s1);
	//settextstyle 设置文本样式，其中第一个参数是字体高度，第二个参数是字体宽度（0 表示自动按比例计算），第三个参数是字体名称。
	settextcolor(WHITE);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void ak_button_music(int x, int y, int w, int h, const char* text, bool judge)
{
	setbkmode(TRANSPARENT);//文字不填充背景色
	if (judge)
	{
		setfillcolor(RED);
	}
	else
	{
		setfillcolor(LIGHTMAGENTA);
	}

	fillroundrect(x, y, x + w, y + h, 10, 10);
	TCHAR s1[] = _T("Arial BLACK");
	settextstyle(30, 0, s1);
	//settextstyle 设置文本样式，其中第一个参数是字体高度，第二个参数是字体宽度（0 表示自动按比例计算），第三个参数是字体名称。
	settextcolor(WHITE);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}


bool inArea(int mx, int my, int x, int y, int w, int h) {
	if (mx > x && mx<x + w && my>y && my < y + h) {
		return true;//设置一个判断鼠标是否在区域里面
	}
	return false;
}
void button(int x, int y, int w, int h, const char* text) {//输入坐标，宽度，字符串实现框框
	if (inArea(msg.x, msg.y, x, y, w, h)) {
		setfillcolor(YELLOW);
	}//判断鼠标是否在框框上 ，在就变颜色
	else
		setfillcolor(DARKGRAY);
	fillroundrect(x, y, x + w, y + h, 5, 5);
	int hs = (w - textwidth(text)) / 2;
	int vs = (h - textheight(text)) / 2;
	settextcolor(WHITE);
	outtextxy(x + hs, y + vs, text);
}




void menuView()
{
	initgraph(ViewWidth, ViewHeight,SHOWCONSOLE);//根据长宽创建窗口
	HWND hwnd = GetHWnd();
	// 设置窗口位置
	// 参数依次为：窗口句柄，窗口的 Z 顺序，x 位置，y 位置，宽度，高度，窗口位置改变的标志
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);
	IMAGE background;
	loadimage(&background, "./picture/bgmian.jpg", ViewWidth, ViewHeight);
	putimage(0, 0, &background);

	ak_button_2(180, 300, 120, 40, "开始游戏");
	ak_button_2(180, 300 + 50, 120, 40, "设置");
	ak_button_2(180, 300 + 50 * 2, 120, 40, "玩法介绍");
	ak_button_2(180, 300 + 50 * 3, 120, 40, "关于我们");
	ak_button_2(180, 300 + 50 * 4, 120, 40, "退出游戏");
	if (music_on) {
		mciSendString("open \"./bgm/bgm.mp3\" type mpegvideo alias bgmusic", NULL, 0, NULL);
		mciSendString("play bgmusic repeat", NULL, 0, NULL);
	}
	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x > 180 && msg.y > 300 && msg.x < 180 + 120 && msg.y < 300 + 40)
		{

			cleardevice();
			gameView();
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x > 180 && msg.y > 300 + 50 && msg.x < 180 + 120 && msg.y < 300 + 50 + 40)
		{
			cleardevice();
			setView();
			//setView();
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x > 180 && msg.y > 300 + 50 * 2 && msg.x < 180 + 120 && msg.y < 300 + 50 * 2 + 40)
		{
			cleardevice();
			introduceView();
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x > 180 && msg.y > 300 + 50 * 3 && msg.x < 180 + 120 && msg.y < 300 + 50 * 3 + 40)
		{
			cleardevice();
			aboutView();
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x > 180 && msg.y > 300 + 50 * 4 && msg.x < 180 + 120 && msg.y < 300 + 50 * 4 + 40)
		{
			closegraph();
			mciSendString("close bgmusic", NULL, 0, NULL);
			exit(0);
		}
	}

}


void gameView()
{
	initgraph(ViewWidth, ViewHeight,SHOWCONSOLE);
	HWND hwnd = GetHWnd();
	// 设置窗口位置
	// 参数依次为：窗口句柄，窗口的 Z 顺序，x 位置，y 位置，宽度，高度，窗口位置改变的标志
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);
	//初始化
	init();


	clock_t startTime = clock();

	while (true) {
		BeginBatchDraw();
		clock_t currentTime = clock();
		if (currentTime >= startTime + CLOCKS_PER_SEC)
		{
			roundTime--;
			startTime = currentTime;
		}
		gameView_ShowMap();
		FlushBatchDraw();
		click_chess();
		if (back_to_main)
		{
			back_to_main = false;
			closegraph();
			EndBatchDraw();
			menuView();
			return;

		}
		if (stop)
		{
			EndBatchDraw();
			stopView();
		}

		if (isWin())
		{
			closegraph();
			EndBatchDraw();
			winView();
			return;
		}

	}
	EndBatchDraw();

	getchar();
}

void setView()
{
	/*initgraph(ViewWidth, ViewHeight);//根据长宽创建窗口
	HWND hwnd = GetHWnd();
	// 设置窗口位置
	// 参数依次为：窗口句柄，窗口的 Z 顺序，x 位置，y 位置，宽度，高度，窗口位置改变的标志
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);*/
	IMAGE background;
	loadimage(&background, "./picture/bgmian.jpg", ViewWidth, ViewHeight);
	putimage(0, 0, &background);

	ak_button_2(80, 300, 160, 40, "音乐播放");
	ak_button_music(300, 300, 40, 40, "开", music_on);
	ak_button_music(360, 300, 40, 40, "关", !music_on);

	ak_button_2(80, 300 + 50, 160, 40, "皮肤选择");
	ak_button_2(300, 300 + 50, 40, 40, "1");
	ak_button_2(350, 300 + 50, 40, 40, "2");
	ak_button_2(400, 300 + 50, 40, 40, "3");

	ak_button_2(80, 300 + 50 * 2, 160, 40, "游戏速度调节");
	ak_button_2(300, 300 + 50 * 2, 40, 40, "30s");
	ak_button_2(350, 300 + 50 * 2, 40, 40, "20s");
	ak_button_2(400, 300 + 50 * 2, 40, 40, "10s");

	IMAGE img2;
	loadimage(&img2, "./picture/back.png", 80, 40);
	putimage(400, 600, &img2);

	while (1)
	{

		if (peekmessage(&msg, EM_MOUSE)) { // 只检查鼠标消息
			if (msg.message == WM_LBUTTONDOWN) { // 如果此时鼠标左键按下
				//判断map[row][col]的值 
				//cleardevice();//清屏
				if (msg.x >= 400 && msg.y >= 600)//退出
				{
					back_to_main = true;

				}
				else if (msg.x >= 360 && msg.y >= 300 && msg.x <= 400 && msg.y <= 340)//关
				{
					mciSendString("close bgmusic", NULL, 0, NULL);
					music_on = false;
					setView();

					return;

				}
				else if (msg.x >= 300 && msg.y >= 300 && msg.x <= 340 && msg.y <= 340)//开
				{
					music_on = true;
					mciSendString("open \"./bgm/bgm.mp3\" type mpegvideo alias bgmusic", NULL, 0, NULL);
					mciSendString("play bgmusic repeat", NULL, 0, NULL);
					setView();

					return;
				}
				else if (msg.x >= 300 && msg.y >= 400 && msg.x <= 340 && msg.y <= 440)//30
				{
					round_Times = 30;

				}
				else if (msg.x >= 350 && msg.y >= 400 && msg.x <= 390 && msg.y <= 440)//20
				{
					round_Times = 20;
				}
				else if (msg.x >= 400 && msg.y >= 400 && msg.x <= 440 && msg.y <= 440)//20
				{
					round_Times = 10;

				}

			}
		}
		if (back_to_main)
		{
			back_to_main = false;
			closegraph();
			menuView();

			return;

		}

	}
}


void musicView() {
}


void introduceView() {
	/*initgraph(ViewWidth, ViewHeight);//根据长宽创建窗口
	HWND hwnd = GetHWnd();
	// 设置窗口位置
	// 参数依次为：窗口句柄，窗口的 Z 顺序，x 位置，y 位置，宽度，高度，窗口位置改变的标志
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);*/
	IMAGE background;
	loadimage(&background, "./picture/rule.jpg", ViewWidth, ViewHeight);
	putimage(0, 0, &background);
	IMAGE img2;
	loadimage(&img2, "./picture/back.png", 80, 40);
	putimage(400, 600, &img2);
	bool show_page = true;
	while (show_page)
	{
		returnMenu();
		if (back_to_main)
		{
			show_page = false;
			back_to_main = false;
			closegraph();
			menuView();
			break;


		}

	}


}


void aboutView()
{
	/*initgraph(ViewWidth, ViewHeight);//根据长宽创建窗口
	HWND hwnd = GetHWnd();
	// 设置窗口位置
	// 参数依次为：窗口句柄，窗口的 Z 顺序，x 位置，y 位置，宽度，高度，窗口位置改变的标志
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);*/
	IMAGE background;
	loadimage(&background, "./picture/aboutus.jpg", ViewWidth, ViewHeight);
	putimage(0, 0, &background);
	IMAGE img2;
	loadimage(&img2, "./picture/back.png", 80, 40);
	putimage(400, 600, &img2);

	while (1)
	{
		returnMenu();
		if (back_to_main)
		{
			back_to_main = false;
			closegraph();
			menuView();
			break;

		}

	}
}



void stopView()
{

	initgraph(ViewWidth, ViewHeight);
	HWND hwnd = GetHWnd();
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);


	IMAGE background;
	loadimage(&background, "./picture/bg1.jpg");
	putimage(0, 0, &background);

	IMAGE img2;
	loadimage(&img2, "./picture/back.png", 80, 40);
	putimage(400, 600, &img2);
	clock_t StartTime = clock();

	//开始计时
	ak_button_2(240 - 75, 320 - 50, 150, 100, "继续游戏");
	while (true) {
		clock_t currentTime = clock();
		/*if (currentTime >= StartTime + CLOCKS_PER_SEC)
		{
			roundTime++;
			if (roundTime > round_Times)
				roundTime = round_Times;
			StartTime = currentTime;
		}*/
		if (peekmessage(&msg, EM_MOUSE)) { // 只检查鼠标消息
			if (msg.message == WM_LBUTTONDOWN) {


				if (inArea(msg.x, msg.y, 150, 300, 150, 100))
				{
					stop = false;
					return;
				}
				if (msg.x >= 400 && msg.y >= 600)
				{
					back_to_main = true;
					stop = false;
					return;
				}
			}
		}


	}

	//暂停界面
	getchar();
}


void winView() {
	initgraph(ViewWidth, ViewHeight);
	HWND hwnd = GetHWnd();
	// 设置窗口位置
	// 参数依次为：窗口句柄，窗口的 Z 顺序，x 位置，y 位置，宽度，高度，窗口位置改变的标志
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);


	IMAGE img;
	loadimage(&img, "./picture/win.jpg", ViewWidth, ViewHeight);

	// 显示图片
	putimage(0, 0, &img);
	// 获取胜利者信息
	int winner = isWin();
	std::string winnerText = (winner == 1) ? "红方胜利" : "蓝方胜利";

	// 显示胜利者文本
	setbkmode(TRANSPARENT);//文字不填充背景色
	setfillcolor(GREEN);
	setcolor(WHITE);
	settextstyle(50, 20, "2");
	int textWidth = textwidth(winnerText.c_str()); // 获得文本宽度
	int centerX = (getmaxx() - textWidth) / 2; // 计算使文本居中的x坐标
	fillroundrect(centerX - 20, 300, centerX + textWidth + 20, 300 + 50, 10, 10);
	outtextxy(centerX, 300, winnerText.c_str()); // 居中显示胜利方信息

	// 创建返回主菜单按钮
	IMAGE img2;
	loadimage(&img2, "./picture/back.png", 80, 40);
	putimage(400, 600, &img2);
	while (1)
	{
		returnMenu();
		if (back_to_main)
		{
			back_to_main = false;
			closegraph();
			menuView();
			break;

		}

	}

}


void gameView_ShowMap()
{
	IMAGE background;
	loadimage(&background, "./picture/bg1.jpg");
	putimage(0, 0, &background);

	IMAGE player;
	if (flag % 2 == 0)//red
	{
		loadimage(&player, "./picture/red.png", 80, 400);
		putimage(400, 0, &player);
	}
	else
	{
		loadimage(&player, "./picture/blue.png", 80, 400);
		putimage(400, 0, &player);

	}
	IMAGE img2;
	loadimage(&img2, "./picture/back.png", 80, 40);
	putimage(400, 600, &img2);
	IMAGE img3;
	loadimage(&img3, "./picture/stop.png", 80, 40);
	putimage(0, 600, &img3);

	// 遍历 map 并在每个单元格中绘制其值
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// 计算当前单元格的位置
			int left = j * BlockSide;
			int top = i * BlockSide;
			int right = (j + 1) * BlockSide;
			int bottom = (i + 1) * BlockSide;
			IMAGE img;
			/*
			1.（背景图）
			2.当前落子的人是谁
			3.暂停按钮，返回主菜单按钮
			4.倒计时
			*/
			rectangle(left, top, right, bottom);

			switch (map[i][j])
			{
			case 0:
			{
				loadimage(&img, "./picture/block.jpg", 100, 100);
				putimage(left, top, &img);
				break;
			}
			case 1:
			{
				loadimage(&img, "./picture/unknown.png", 100, 100);
				putimage(left, top, &img);
				break;
			}
			case 2:
			{
				loadimage(&img, "./picture/fire.jpg", 100, 100);
				putimage(left, top, &img);
				break;
			}
			default:
			{
				string temp = "./picture/" + to_string(map[i][j]) + ".png";
				loadimage(&img, temp.c_str(), 100, 100);
				putimage(left, top, &img);
				break;
			}
			}

		}
	}

	timeView();
}

void timeView()
{

	TCHAR round[] = _T("倒计时只剩下：");
	settextcolor(BLUE);
	settextstyle(25, 10, _T("楷体"));
	TCHAR str[100];
	_stprintf_s(str, _T("%s%d"), round, roundTime);
	ak_button(0, 400, 250, 40, str);

}


void returnMenu() {

	if (peekmessage(&msg, EM_MOUSE)) { // 只检查鼠标消息
		if (msg.message == WM_LBUTTONDOWN) { // 如果此时鼠标左键按下
			//判断map[row][col]的值 
			//cleardevice();//清屏
			if (msg.x >= 400 && msg.y >= 600)
			{
				back_to_main = true;
				return;
			}

		}
	}
}



