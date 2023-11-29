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
	// ���ݴ���ĺϷ������� (x,y) �жϸ�λ���Ƿ�Ϊδ����״̬�����������ִ�� if ��ֱ�ӷ���
	if (map[x][y] == 1) {
		// �������������
		srand((unsigned)time(NULL));

		// �����ȡ animal ���±꣬�� animal �ж�Ӧ�±��Ԫ�ظ�ֵ��map��ͼ 
		int index = rand() % animal.size();
		map[x][y] = animal[index];

		// �� animal �ж�Ӧ�±��Ԫ��ɾ��
		animal.erase(animal.begin() + index);
		flag++;
		roundTime = round_Times;
		PlaySound(TEXT("./bgm/kill.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return;
	}

	return;
}
int playerMove(int x, int y, int d_x, int d_y) {
	// �ж�ѡ�е�λ�õ������Ƿ�����ƶ���������ֱ�ӷ��� 0
	if (isMove(x, y, d_x, d_y) == 1) {
		// (x,y)ҪΪ��ǰ�غ�����Ӧ�� �췽/���� �ѷ��������ӣ�(d_x,d_y)ҪΪ �յ�/�з��Ѿ�����������------��isMove���Ѿ�����ж�
		// ���ݴ����Ҫ�ƶ��ĺϷ���Ŀ�ĵؽ����жϣ����Ŀ�ĵ���Ϊ�з�����
		if (map[d_x][d_y] > 10) {
			// ��ȡ��ǰΪ�ķ��Ļغ�---�췽Ϊture��������Ϊfalse
			//flag =10 ��ɫ���壬round=true
			// ����ʳ������ϵ���ж���Ӯ
			if (map[x][y] % 10 == 8 && map[d_x][d_y] % 10 ==1) {
				// 1����2����
				map[x][y] = 0;
				cout << "flag��" << flag << endl;
				if (flag % 2 == 0) { // 1��ײ2��   ��ɫ���� �챻��ɫ����
					deathCountRed++;
				}
				else {
					deathCountBlue++;
				}
				flag++;
			}
			else if (map[x][y] % 10 == 1 && map[d_x][d_y] % 10 == 8){
				// 1����2����
				map[d_x][d_y] = map[x][y];
				map[x][y] = 0;
				if (flag % 2 == 0) { // 1��ײ2��   ��ɫ���� �����ɫ����
					deathCountBlue++;
				}
				else {
					deathCountRed++;
				}
				flag++;
			}
			else if (map[x][y] % 10 > map[d_x][d_y] % 10) {
				//�ų����������⣬֮����Ǵ�ĳ�С��
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
				//С��ײ�����
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
				//����˫��ȫΪ������
				map[x][y] = 0;
				map[d_x][d_y] = 0;

				deathCountRed++;
				deathCountBlue++;
				flag++;
			}
			else if (map[x][y] % 10 == map[d_x][d_y] % 10 ) {
				//ͬ���ھ�
				map[x][y] = 0;
				map[d_x][d_y] = 0;

				deathCountRed++;
				deathCountBlue++;
				flag++;
			}
			PlaySound(TEXT("./bgm/kill.wav"), NULL, SND_FILENAME | SND_ASYNC);
			// ��ƽ�غ�������
			peaceFlag = 0;
		}
		else {
			map[d_x][d_y] = map[x][y];
			map[x][y] = 0;
			flag++;

			// ���Ӻ�ƽ�غ���
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
	// �ж�Ŀ����Ƿ�Խ��
	if (d_x < 0 || d_x >= 4 || d_y < 0 || d_y >= 4)
	{
		return 0;
	}
	// �ж�Ŀ����Ƿ�Ϊ�յ�
	// �ж�Ŀ����Ƿ��л�
	if (map[d_x][d_y] == 2   || map[d_x][d_y] == 1)
	{
		return 0;
	}
	// �ж�Ŀ����Ƿ����Լ�������
	if (map[d_x][d_y] / 10 == map[x][y] / 10)
	{
		return 0;
	}
	// �ж��Ƿ�����ƶ���Ŀ���
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

	if (peaceFlag >= Fire_Max_Flag)                         //�ж�Ҫ���Ƿ����
	{

		bool judge = false;                             //����һ��vector����洢λ��Ϊ0�ĵط�
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[i][j] == 0)
					judge = true;
			}
		}
		if (judge)//�пյؿ����Ż�
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

	if (deathCountRed == 8 || deathCountBlue == 8) {//�ж��Ƿ�������8����
		if (deathCountRed == 8 && deathCountBlue == 8) {//����������8�����Ծ���
			if (flag % 2 == 1) return 1;
			if (flag % 2 == 0) return 2;
		}
		if (deathCountRed == 8) return 2;//��������һ������
		else if (deathCountBlue == 8) return 1;
	}
	return 0;
}

void click_chess()
{
	if (peekmessage(&msg, EM_MOUSE)) { // ֻ��������Ϣ
		if (msg.message == WM_LBUTTONDOWN) { // �����ʱ����������
			int row = msg.y / BlockSide; //��Ӧx������
			int col = msg.x / BlockSide;//��Ӧy������
			//�ж�map[row][col]��ֵ 
			//cleardevice();//����
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
				// ��һ�ε��
				firstRow = row;
				firstCol = col;
				if (map[row][col] == 0|| map[row][col] == 2)//�㵽�յػ��߻��
				{
					return;
				}
				else if (map[row][col] == 1)//�㵽δ������������
				{
					cout << "��������" << endl;
					turnChess(row, col);
				}
				else if (map[row][col] > 10)//�㵽�������޵�����
				{
					int player_flag = map[row][col] / 10;//1�Ǻ�ɫ������ 2����ɫ������
					int player_except_flag = flag % 2;//Ϊ0ʱ�Ǻ�ɫ Ϊ1ʱ����ɫ  �����ʱflag��10 ��11�غϣ��췽���� ��ʱΪ0
					if (player_flag == (player_except_flag + 1))//������Լ�������
					{
						cout << "��һ�ε�����"<<row<<col<<endl;
						isFirstClick = false;//���˴ε������ƶ������󣬸ı�˲���
					}
					else //����Ǳ��˵�����
					{
						isFirstClick = true;
						return;
					}
				}			
			}
			else {
				// �ڶ��ε��
				secondRow = row;
				secondCol = col;
				cout << "�ڶ�������" << row << col << endl;
				playerMove(firstRow, firstCol, secondRow, secondCol);
				//int judge=playerMove(firstRow, firstCol, secondRow, secondCol);
				//if (judge)
					//cout << "�ƶ��ɹ�"<<endl;
				cout << deathCountRed <<"_R______B_" << deathCountBlue << endl;
				cout <<"flag:" << flag << " "<< "peace: " << peaceFlag << endl;
				
				// ���õ��״̬
				isFirstClick = true;
			}

			
		}
	}

}




