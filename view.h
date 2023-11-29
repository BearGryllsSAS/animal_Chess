#include"Animal chess.h"
#include"service.h"
//--------------view---------------

void ak_button(int x, int y, int w, int h, TCHAR* text);
void ak_button_2(int x, int y, int w, int h, const char* text);
void ak_button_music(int x, int y, int w, int h, const char* text, bool judge);
bool inArea(int mx, int my, int x, int y, int w, int h);
void button(int x, int y, int w, int h, TCHAR* text); //�������꣬��ȣ��ַ���ʵ�ֿ��

/*
	�����ˣ�С��
	���ܣ�
		չʾ����ѡ�
			��ʼ��Ϸ
			����
			�淨����
			��������
			�˳���Ϸ
		ͨ�������ȷ��

		��ʼ��Ϸ:gameView();
		����:setView();
		�淨����:introduceView();
		��������:aboutView();
		�˳���Ϸ:exit(0);
	������void
	����ֵ��void
*/
void menuView();

/*
	�����ˣ�����
	���ܣ�
		��Ϸ���ܣ�
			��ʼ����Ϸ����(����init())
			while(1)
			{
				չʾ����Ϸ����������showButton()��
				չʾ��Ϸ���̣�����gameView_ShowMap()��

				if(����20�غ�û�����ӱ���)	���ɻ𣨵���fire()��

				��ʼ�غϵ���ʱ������countDown()��
				������չʾ������timeView()��

				������������Ϣ�������壨����turnChess()��/���壨����playerMove()��/���䣨����winView()��ͬʱ�˳�ѭ����
				/��ͣ������stopView()��
				�����ʱ�䳬����roundTime�����winView(),�жԷ�ʤ�����˳�ѭ����
				������漰���������ת��������Ҫ����չʾ��Ϸ����
				  ������ͣ���������ͣ���棬ȡ����ͣ����Ҫ����չʾ��Ϸ���棩

				�ж���Ϸ�Ƿ����������isWin()��
				 �����ʤ��������winView(),������ǰ����,�������˵�(����returnMenu())��

				�л���ң��޸�flag��peaceFlag��
			}
	������void
	����ֵ��void
*/
void gameView();

/*
	�����ˣ���
	���ܣ�
		չʾ����ѡ�
			����
			��Ϸ�ٶȵ���	1~5�ȼ�
			Ƥ��ѡ��
			�������˵�(����returnMenu())
		ͨ�������ȷ��

		����:musicView();
		�ٶȵ��ڡ�Ƥ��ѡ���ѡ���ֱ����ʾ
	������int x,int y
		��ʾ�������λ��
	����ֵ��bool
		0	��ʾδ���
		1	��ʾ���
*/
void setView();

/*
	�����ˣ�charlottee
	���ܣ�
		չʾ���¹��ܣ�
			����ѡ��
			��������	1~5�ȼ�
			���ֿ���
			�������ý���
		ͨ�������ȷ��

	������int x,int y
		��ʾ�������λ��
	����ֵ��bool
		0	��ʾδ���
		1	��ʾ���
*/
void musicView();

/*
	�����ˣ�Ginko
	���ܣ�
		չʾ����ѡ�
			�����淨����
			�������˵�(����returnMenu())
		ͨ�������ȷ��
	������void
	����ֵ��void
*/
void introduceView();

/*
	�����ˣ���
	���ܣ�
		չʾ����ѡ�
			�Ŷӡ������Ƚ���
			�������˵�(����returnMenu())
		ͨ�������ȷ��
	������void
	����ֵ��void
*/
void aboutView();

/*
	�����ˣ�����
	���ܣ�
		չʾ��ͣ����
		�������˵�(����returnMenu())

		��Ҫдһ����ѭ����Ϊ��ȡ����ͣʱ���ܼ�����ʱ
	������void
	����ֵ��void
*/
void stopView();

/*
	�����ˣ�����
	���ܣ�
		չʾʤ������
		�������˵�(����returnMenu())
	������void
	����ֵ��void
*/
void winView();

/*
	�����ˣ�����
	���ܣ�
		����map����	��ӡ����
		ͬʱ���ݾ����ֵ  ��ӡ����
	������void
	����ֵ��void
*/
void gameView_ShowMap();

/*
	�����ˣ�Īһ
	���ܣ�
		չʾ����ʱ
		����ȫ�ֱ���roundTime��ӡʣ��غ�ʱ��
	������void
	����ֵ��void
*/
void timeView();

/*
	�����ˣ�����
	���ܣ�
		�������˵�
		(�ܶ���涼��Ҫ�������˵���������װ��һ������)
	������int x,int y
		��ʾ�������λ��
	����ֵ��int
		0	��ʾδ���
		1	��ʾ������������˵�
*/

void returnMenu();



//--------------view---------------