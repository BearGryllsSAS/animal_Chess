#include "view.h"

void ak_button(int x, int y, int w, int h, TCHAR* text)
{
	setbkmode(TRANSPARENT);//���ֲ���䱳��ɫ
	setfillcolor(GREEN);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	TCHAR s1[] = _T("Arial BLACK");
	settextstyle(30, 0, s1);
	//settextstyle �����ı���ʽ�����е�һ������������߶ȣ��ڶ��������������ȣ�0 ��ʾ�Զ����������㣩���������������������ơ�
	settextcolor(WHITE);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void ak_button_2(int x, int y, int w, int h, const char* text)
{
	setbkmode(TRANSPARENT);//���ֲ���䱳��ɫ

	setfillcolor(LIGHTMAGENTA);

	fillroundrect(x, y, x + w, y + h, 10, 10);
	TCHAR s1[] = _T("Arial BLACK");
	settextstyle(30, 0, s1);
	//settextstyle �����ı���ʽ�����е�һ������������߶ȣ��ڶ��������������ȣ�0 ��ʾ�Զ����������㣩���������������������ơ�
	settextcolor(WHITE);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void ak_button_music(int x, int y, int w, int h, const char* text, bool judge)
{
	setbkmode(TRANSPARENT);//���ֲ���䱳��ɫ
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
	//settextstyle �����ı���ʽ�����е�һ������������߶ȣ��ڶ��������������ȣ�0 ��ʾ�Զ����������㣩���������������������ơ�
	settextcolor(WHITE);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}


bool inArea(int mx, int my, int x, int y, int w, int h) {
	if (mx > x && mx<x + w && my>y && my < y + h) {
		return true;//����һ���ж�����Ƿ�����������
	}
	return false;
}
void button(int x, int y, int w, int h, const char* text) {//�������꣬��ȣ��ַ���ʵ�ֿ��
	if (inArea(msg.x, msg.y, x, y, w, h)) {
		setfillcolor(YELLOW);
	}//�ж�����Ƿ��ڿ���� ���ھͱ���ɫ
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
	initgraph(ViewWidth, ViewHeight,SHOWCONSOLE);//���ݳ���������
	HWND hwnd = GetHWnd();
	// ���ô���λ��
	// ��������Ϊ�����ھ�������ڵ� Z ˳��x λ�ã�y λ�ã���ȣ��߶ȣ�����λ�øı�ı�־
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);
	IMAGE background;
	loadimage(&background, "./picture/bgmian.jpg", ViewWidth, ViewHeight);
	putimage(0, 0, &background);

	ak_button_2(180, 300, 120, 40, "��ʼ��Ϸ");
	ak_button_2(180, 300 + 50, 120, 40, "����");
	ak_button_2(180, 300 + 50 * 2, 120, 40, "�淨����");
	ak_button_2(180, 300 + 50 * 3, 120, 40, "��������");
	ak_button_2(180, 300 + 50 * 4, 120, 40, "�˳���Ϸ");
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
	// ���ô���λ��
	// ��������Ϊ�����ھ�������ڵ� Z ˳��x λ�ã�y λ�ã���ȣ��߶ȣ�����λ�øı�ı�־
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);
	//��ʼ��
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
	/*initgraph(ViewWidth, ViewHeight);//���ݳ���������
	HWND hwnd = GetHWnd();
	// ���ô���λ��
	// ��������Ϊ�����ھ�������ڵ� Z ˳��x λ�ã�y λ�ã���ȣ��߶ȣ�����λ�øı�ı�־
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);*/
	IMAGE background;
	loadimage(&background, "./picture/bgmian.jpg", ViewWidth, ViewHeight);
	putimage(0, 0, &background);

	ak_button_2(80, 300, 160, 40, "���ֲ���");
	ak_button_music(300, 300, 40, 40, "��", music_on);
	ak_button_music(360, 300, 40, 40, "��", !music_on);

	ak_button_2(80, 300 + 50, 160, 40, "Ƥ��ѡ��");
	ak_button_2(300, 300 + 50, 40, 40, "1");
	ak_button_2(350, 300 + 50, 40, 40, "2");
	ak_button_2(400, 300 + 50, 40, 40, "3");

	ak_button_2(80, 300 + 50 * 2, 160, 40, "��Ϸ�ٶȵ���");
	ak_button_2(300, 300 + 50 * 2, 40, 40, "30s");
	ak_button_2(350, 300 + 50 * 2, 40, 40, "20s");
	ak_button_2(400, 300 + 50 * 2, 40, 40, "10s");

	IMAGE img2;
	loadimage(&img2, "./picture/back.png", 80, 40);
	putimage(400, 600, &img2);

	while (1)
	{

		if (peekmessage(&msg, EM_MOUSE)) { // ֻ��������Ϣ
			if (msg.message == WM_LBUTTONDOWN) { // �����ʱ����������
				//�ж�map[row][col]��ֵ 
				//cleardevice();//����
				if (msg.x >= 400 && msg.y >= 600)//�˳�
				{
					back_to_main = true;

				}
				else if (msg.x >= 360 && msg.y >= 300 && msg.x <= 400 && msg.y <= 340)//��
				{
					mciSendString("close bgmusic", NULL, 0, NULL);
					music_on = false;
					setView();

					return;

				}
				else if (msg.x >= 300 && msg.y >= 300 && msg.x <= 340 && msg.y <= 340)//��
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
	/*initgraph(ViewWidth, ViewHeight);//���ݳ���������
	HWND hwnd = GetHWnd();
	// ���ô���λ��
	// ��������Ϊ�����ھ�������ڵ� Z ˳��x λ�ã�y λ�ã���ȣ��߶ȣ�����λ�øı�ı�־
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
	/*initgraph(ViewWidth, ViewHeight);//���ݳ���������
	HWND hwnd = GetHWnd();
	// ���ô���λ��
	// ��������Ϊ�����ھ�������ڵ� Z ˳��x λ�ã�y λ�ã���ȣ��߶ȣ�����λ�øı�ı�־
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

	//��ʼ��ʱ
	ak_button_2(240 - 75, 320 - 50, 150, 100, "������Ϸ");
	while (true) {
		clock_t currentTime = clock();
		/*if (currentTime >= StartTime + CLOCKS_PER_SEC)
		{
			roundTime++;
			if (roundTime > round_Times)
				roundTime = round_Times;
			StartTime = currentTime;
		}*/
		if (peekmessage(&msg, EM_MOUSE)) { // ֻ��������Ϣ
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

	//��ͣ����
	getchar();
}


void winView() {
	initgraph(ViewWidth, ViewHeight);
	HWND hwnd = GetHWnd();
	// ���ô���λ��
	// ��������Ϊ�����ھ�������ڵ� Z ˳��x λ�ã�y λ�ã���ȣ��߶ȣ�����λ�øı�ı�־
	SetWindowPos(hwnd, HWND_TOP, 100, 100, 0, 0, SWP_NOSIZE);


	IMAGE img;
	loadimage(&img, "./picture/win.jpg", ViewWidth, ViewHeight);

	// ��ʾͼƬ
	putimage(0, 0, &img);
	// ��ȡʤ������Ϣ
	int winner = isWin();
	std::string winnerText = (winner == 1) ? "�췽ʤ��" : "����ʤ��";

	// ��ʾʤ�����ı�
	setbkmode(TRANSPARENT);//���ֲ���䱳��ɫ
	setfillcolor(GREEN);
	setcolor(WHITE);
	settextstyle(50, 20, "2");
	int textWidth = textwidth(winnerText.c_str()); // ����ı����
	int centerX = (getmaxx() - textWidth) / 2; // ����ʹ�ı����е�x����
	fillroundrect(centerX - 20, 300, centerX + textWidth + 20, 300 + 50, 10, 10);
	outtextxy(centerX, 300, winnerText.c_str()); // ������ʾʤ������Ϣ

	// �����������˵���ť
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

	// ���� map ����ÿ����Ԫ���л�����ֵ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// ���㵱ǰ��Ԫ���λ��
			int left = j * BlockSide;
			int top = i * BlockSide;
			int right = (j + 1) * BlockSide;
			int bottom = (i + 1) * BlockSide;
			IMAGE img;
			/*
			1.������ͼ��
			2.��ǰ���ӵ�����˭
			3.��ͣ��ť���������˵���ť
			4.����ʱ
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

	TCHAR round[] = _T("����ʱֻʣ�£�");
	settextcolor(BLUE);
	settextstyle(25, 10, _T("����"));
	TCHAR str[100];
	_stprintf_s(str, _T("%s%d"), round, roundTime);
	ak_button(0, 400, 250, 40, str);

}


void returnMenu() {

	if (peekmessage(&msg, EM_MOUSE)) { // ֻ��������Ϣ
		if (msg.message == WM_LBUTTONDOWN) { // �����ʱ����������
			//�ж�map[row][col]��ֵ 
			//cleardevice();//����
			if (msg.x >= 400 && msg.y >= 600)
			{
				back_to_main = true;
				return;
			}

		}
	}
}



