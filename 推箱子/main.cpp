
#include<iostream>
#include<string.h>
using namespace std;
#pragma warning (disable:4996)
#define M 10
#define N 10
 
//����һ��10*10��ͼ,1��ʾǽ,0��ʾ�յ�,2��ʾ��
//3��ʾ����,4��ʾ�ɹ���
//1.�������վ���ɹ�����,��ʾ��
//2.��������ɹ����,�����Ƴ���
//3.��¼����,��ʾ�ڿ���̨��
//4.����:��ʾ(������ǽ....)/��Ϸ��ʼ����
//5.������ʾȫ������,��ʾ�ɹ�
//��Χ����ǽ,�м䶼�ǿյ�
#include"Map.h"
#include"Game.h"
int main()
{
	Map _map;
	//_map.Init();
	int map[M][N];
	char filename[] = "map/map_0";
	int custom = 2;
	while (custom <= 5)
	{
		char buffer[80];
		sprintf(buffer, "%s%d", filename, custom);         //����filename��custom,���ַ������浽buffer��
		strcat(buffer, ".txt");                            //�ַ�������
		_map.ReadMapFile(map, N, buffer);
		Game game;
		int step = 0;
		while (game.juide(map))                           //��Ϸʤ��������ѭ��
		{
			system("cls");
			game.Drop(map, custom);
			char ch = _getch();                           //��������
			step = game.Move(map, ch);
			system("cls");
		}
		custom++;                            //�ؿ�+1
		cout << "��Ӯ��!" << endl;
		cout << "���ߣ�" << step << "��" << endl;;
		system("pause");
		
	}
	
	
	return 0;
}